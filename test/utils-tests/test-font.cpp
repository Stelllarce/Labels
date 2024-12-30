#include "catch2/catch_all.hpp"
#include "utils/StyledFont.hpp"

TEST_CASE("Valid format", "[StyledFont]") {
    StyledFont font("Arial", 12);
    REQUIRE(font.getName() == "Arial");
    REQUIRE(font.getSize() == 12);
}

TEST_CASE("Empty name", "[StyledFont]") {
    REQUIRE_THROWS_AS(StyledFont("", 12), std::invalid_argument);
}

TEST_CASE("Zero size", "[StyledFont]") {
    REQUIRE_THROWS_AS(StyledFont("Arial", 0), std::invalid_argument);
}

TEST_CASE("Size greater than max", "[StyledFont]") {
    REQUIRE_THROWS_AS(StyledFont("Arial", 1700), std::invalid_argument);
}
