#include "catch2/catch_all.hpp"
#include "utils/Color.hpp"

TEST_CASE("Valid color, hex ctor", "[Color]") {
    Color color(0x00FF00);
    REQUIRE(color.getColor() == 0x00FF00);
}

TEST_CASE("Valid color, rgb ctor", "[Color]") {
    Color color(0, 255, 0);
    REQUIRE(color.getColor() == 0x00FF00);
}

TEST_CASE("Color greater than max", "[Color]") {
    REQUIRE_THROWS_AS(Color(0x1000000), std::invalid_argument);
}