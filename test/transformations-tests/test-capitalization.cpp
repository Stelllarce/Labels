#include "catch2/catch_all.hpp"
#include "transformations/CapitalizeTransformation.hpp"

TEST_CASE("Normal text", "[CapitalizeTransformation]") {
    CapitalizeTransformation transformation;
    REQUIRE(transformation.transform("design patterns") == "Design patterns");
    REQUIRE(transformation.transform("Hello") == "Hello");
    REQUIRE(transformation.transform("PATTERNS DESIGN") == "PATTERNS DESIGN");
}

TEST_CASE("Text with special characters, no change", "[CapitalizeTransformation]") {
    CapitalizeTransformation transformation;
    REQUIRE(transformation.transform("1234") == "1234");
    REQUIRE(transformation.transform("!!!") == "!!!");
}

