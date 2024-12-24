#include "catch2/catch_all.hpp"
#include "utils/Font.hpp"

TEST_CASE("Valid format", "[Font]") {
    Font font("Arial", 12);
    REQUIRE(font.getName() == "Arial");
    REQUIRE(font.getSize() == 12);
}

TEST_CASE("Empty name", "[Font]") {
    REQUIRE_THROWS_AS(Font("", 12), std::invalid_argument);
}

TEST_CASE("Zero size", "[Font]") {
    REQUIRE_THROWS_AS(Font("Arial", 0), std::invalid_argument);
}

TEST_CASE("Size greater than max", "[Font]") {
    REQUIRE_THROWS_AS(Font("Arial", 1700), std::invalid_argument);
}
