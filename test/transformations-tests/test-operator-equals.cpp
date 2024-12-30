#include "catch2/catch_all.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/RightTrimTransformation.hpp"
#include "transformations/LeftTrimTransformation.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/CensorTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"
#include <vector>

TEST_CASE("ReplaceTransformation operator==", "[ReplaceTransformation]") {
    ReplaceTransformation t1("old", "new");
    ReplaceTransformation t2("old", "new");
    ReplaceTransformation t3("old", "different");

    REQUIRE(t1 == t2);
    REQUIRE_FALSE(t1 == t3);
}

TEST_CASE("NormalizeSpaceTransformation operator==", "[NormalizeSpaceTransformation]") {
    NormalizeSpaceTransformation t1;
    NormalizeSpaceTransformation t2;

    REQUIRE(t1 == t2);
}

TEST_CASE("RightTrimTransformation operator==", "[RightTrimTransformation]") {
    RightTrimTransformation t1;
    RightTrimTransformation t2;

    REQUIRE(t1 == t2);
}

TEST_CASE("LeftTrimTransformation operator==", "[LeftTrimTransformation]") {
    LeftTrimTransformation t1;
    LeftTrimTransformation t2;

    REQUIRE(t1 == t2);
}

TEST_CASE("CapitalizeTransformation operator==", "[CapitalizeTransformation]") {
    CapitalizeTransformation t1;
    CapitalizeTransformation t2;

    REQUIRE(t1 == t2);
}

TEST_CASE("CensorTransformation operator==", "[CensorTransformation]") {
    CensorTransformation t1("badword");
    CensorTransformation t2("badword");
    CensorTransformation t3("differentword");

    REQUIRE(t1 == t2);
    REQUIRE_FALSE(t1 == t3);
}

TEST_CASE("DecorateTransformation operator==",  "[DecorateTransformation]") {
    DecorateTransformation t1;
    DecorateTransformation t2;
    DecorateTransformation t3;

    REQUIRE(t1 == t2);
}

static bool compareAllTransformations() {
    std::vector<std::shared_ptr<TextTransformation>> transformations{
        std::make_shared<ReplaceTransformation>("old", "new"),
        std::make_shared<NormalizeSpaceTransformation>(),
        std::make_shared<RightTrimTransformation>(),
        std::make_shared<LeftTrimTransformation>(),
        std::make_shared<CapitalizeTransformation>(),
        std::make_shared<CensorTransformation>("badword"),
        std::make_shared<DecorateTransformation>()
    };

    for(size_t i = 0; i < transformations.size(); i++) {
        for(size_t j = 0; j < transformations.size(); j++) {
            if(i == j) {
                if(!(*transformations[i] == *transformations[j])) return false;
            } else {
                if(*transformations[i] == *transformations[j]) return false;
            }
        }
    }
    return true;
}

TEST_CASE("Compare every two transformations") {
    REQUIRE(compareAllTransformations());
}