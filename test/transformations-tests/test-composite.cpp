#include "catch2/catch_all.hpp"
#include "transformations/CompositeTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/CensorTransformation.hpp"

TEST_CASE("Apply no transformations", "[CompositeTransformation]") {
    CompositeTransformation transformation({});
    REQUIRE(transformation.transform("Simply an example") == "Simply an example");
}

TEST_CASE("Apply one transformation", "[CompositeTransformation]") {
    CompositeTransformation transformation({std::make_shared<DecorateTransformation>()});
    REQUIRE(transformation.transform("Simply an example") == "-={ Simply an example }=-");
}

TEST_CASE("Apply multiple transformations", "[CompositeTransformation]") {
    CompositeTransformation transformations = {
        std::make_shared<ReplaceTransformation>("that", "this"),
        std::make_shared<CensorTransformation>("this"),
        std::make_shared<ReplaceTransformation>("why", "look, "),
        std::make_shared<CensorTransformation>("ook"),
        std::make_shared<CapitalizeTransformation>(),
        std::make_shared<NormalizeSpaceTransformation>(), 
        std::make_shared<DecorateTransformation>()
        };
    REQUIRE(transformations.transform("why that  is simply an    example!") == "-={ L***, **** is simply an example! }=-");
}