#include "catch2/catch_all.hpp"
#include "transformations/RightTrimTransformation.hpp"

TEST_CASE("No trailing spaces", "[RightTrimTransformation]") {
    RightTrimTransformation transformation;
    REQUIRE(transformation.transform("design patterns") == "design patterns");
}

TEST_CASE("One trailing space", "[RightTrimTransformation]") {
    RightTrimTransformation transformation;
    REQUIRE(transformation.transform("design patterns ") == "design patterns");
}

TEST_CASE("Multiple trailing spaces", "[RightTrimTransformation]") {
    RightTrimTransformation transformation;
    REQUIRE(transformation.transform("design patterns    ") == "design patterns");
}

TEST_CASE("Empty text", "[RightTrimTransformation]") {
    RightTrimTransformation transformation;
    REQUIRE_THROWS_WITH(transformation.transform(""), "Empty text, nothing to trim");
}