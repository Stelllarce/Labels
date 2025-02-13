#include "catch2/catch_all.hpp"
#include "transformations/CompositeTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/CensorTransformation.hpp"

TEST_CASE("Apply no transformations", "[CompositeTransformation]") {
    auto transformation = std::make_unique<CompositeTransformation>();
    REQUIRE(transformation->transform("Simply an example") == "Simply an example");
}

TEST_CASE("Apply one transformation", "[CompositeTransformation]") {
    auto transformation = CompositeTransformation::create(
        std::make_unique<DecorateTransformation>()
    );
    REQUIRE(transformation->transform("Simply an example") == "-={ Simply an example }=-");
}

TEST_CASE("Apply multiple transformations", "[CompositeTransformation]") {
    auto transformations = CompositeTransformation::create(
        std::make_unique<ReplaceTransformation>("that", "this"),
        std::make_unique<CensorTransformation>("this"),
        std::make_unique<ReplaceTransformation>("why", "look, "),
        std::make_unique<CensorTransformation>("ook"),
        std::make_unique<CapitalizeTransformation>(),
        std::make_unique<NormalizeSpaceTransformation>(),
        std::make_unique<DecorateTransformation>()
    );
    REQUIRE(transformations->transform("why that  is simply an    example!") == "-={ L***, **** is simply an example! }=-");
}

TEST_CASE("Adding a transformation", "[CompositeTransformation]") {
    auto transformations = CompositeTransformation::create(
        std::make_unique<ReplaceTransformation>("that", "this"),
        std::make_unique<CensorTransformation>("this"),
        std::make_unique<ReplaceTransformation>("why", "look, "),
        std::make_unique<CensorTransformation>("ook"),
        std::make_unique<CapitalizeTransformation>(),
        std::make_unique<NormalizeSpaceTransformation>(),
        std::make_unique<DecorateTransformation>()
    );
    transformations->add(std::make_unique<ReplaceTransformation>("simply", "just"));
    REQUIRE(transformations->transform("why that  is simply an    example!") == "-={ L***, **** is just an example! }=-");
}

TEST_CASE("Removing a transformation", "[CompositeTransformation]") {
    auto transformations = CompositeTransformation::create(
        std::make_unique<ReplaceTransformation>("that", "this"),
        std::make_unique<CensorTransformation>("this"),
        std::make_unique<ReplaceTransformation>("why", "look, "),
        std::make_unique<CensorTransformation>("ook"),
        std::make_unique<CapitalizeTransformation>(),
        std::make_unique<NormalizeSpaceTransformation>(),
        std::make_unique<DecorateTransformation>()
    );
    
    auto to_remove = std::make_unique<CensorTransformation>("this");
    transformations->remove(*to_remove);
    REQUIRE(transformations->transform("why that  is simply an    example!") == "-={ L***, this is simply an example! }=-");
}