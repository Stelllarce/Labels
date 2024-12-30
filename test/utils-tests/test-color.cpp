#include "catch2/catch_all.hpp"
#include "utils/HexColor.hpp"

TEST_CASE("Valid color, hex ctor", "[HexColor]") {
    HexColor color(0x00FF00);
    REQUIRE(color.getColor() == "0xFF00");
}

TEST_CASE("Valid color, rgb ctor", "[HexColor]") {
    HexColor color(0, 255, 0);
    REQUIRE(color.getColor() == "0xFF00");
}

TEST_CASE("HexColor greater than max", "[HexColor]") {
    REQUIRE_THROWS_AS(HexColor(0x1000000), std::invalid_argument);
}