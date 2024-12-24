#include "catch2/catch_all.hpp"
#include "transformations/DecorateTransformation.hpp"

TEST_CASE("Simple decoration", "[DecorateTransformation]") {
    DecorateTransformation decorator;
    REQUIRE(decorator.transform("Soon To be Pretty Label") == "-={ Soon To be Pretty Label }=-");
}

TEST_CASE("Empty text", "[DecorateTransformation]") {
    DecorateTransformation decorator;
    REQUIRE_THROWS_WITH(decorator.transform(""), "Empty text, nothing to decorate");
}