#include "catch2/catch_all.hpp"
#include "transformations/DecorateTransformation.hpp"

TEST_CASE("Simple decoration", "[DecorateTransformation]") {
    DecorateTransformation decorator;
    REQUIRE(decorator.transform("Soon To be Pretty Label") == "-={ Soon To be Pretty Label }=-");
}