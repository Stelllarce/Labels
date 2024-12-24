#include "catch2/catch_all.hpp"
#include "transformations/LeftTrimTransformation.hpp"

TEST_CASE("Single space", "[LeftTrimTransformation]") {
    LeftTrimTransformation transformation;
    REQUIRE(transformation.transform(" design patterns") == "design patterns");
    REQUIRE(transformation.transform(" Hello") == "Hello");
}

TEST_CASE("Multiple spaces", "[LeftTrimTransformation]") {
    LeftTrimTransformation transformation;
    REQUIRE(transformation.transform("    design patterns") == "design patterns");
    REQUIRE(transformation.transform("    Hello") == "Hello");
}

TEST_CASE("No spaces", "[LeftTrimTransformation]") {
    LeftTrimTransformation transformation;
    REQUIRE(transformation.transform("design patterns") == "design patterns");
}

TEST_CASE("Space, character, space", "[LeftTrimTransformation]") {
    LeftTrimTransformation transformation;
    REQUIRE(transformation.transform(" d esign p") == "d esign p");
}

TEST_CASE("Empty text", "[LeftTrimTransformation]") {
    LeftTrimTransformation transformation;
    REQUIRE_THROWS_WITH(transformation.transform(""), "Empty text, nothing to trim");
}