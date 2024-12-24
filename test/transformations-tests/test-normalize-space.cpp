#include "catch2/catch_all.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"

TEST_CASE("No consecutive spaces in the middle of the text", "[NormalizeTextTransformation]") {
    NormalizeSpaceTransformation transformer;
    std::string input = "This is a test.";
    std::string expected = "This is a test.";
    REQUIRE(transformer.transform(input) == expected);
}

TEST_CASE("Consecutive spaces only in the middle", "[NormalizeTextTransformation]") {
    NormalizeSpaceTransformation transformer;
    std::string input = "This  is      a         test.";
    std::string expected = "This is a test.";
    REQUIRE(transformer.transform(input) == expected);
}

TEST_CASE("Consecutive spaces at the front and middle", "[NormalizeTextTransformation]") {
    NormalizeSpaceTransformation transformer;
    std::string input = "This      is a test.";
    std::string expected = "This is a test.";
    REQUIRE(transformer.transform(input) == expected);
}

TEST_CASE("Consecutive spaces in the middle and back", "[NormalizeTextTransformation]") {
    NormalizeSpaceTransformation transformer;
    std::string input = "This is  a    test.";
    std::string expected = "This is a test.";
    REQUIRE(transformer.transform(input) == expected);
}

TEST_CASE("Empty text", "[NormalizeTextTransformation]") {
    NormalizeSpaceTransformation transformer;
    REQUIRE_THROWS_WITH(transformer.transform(""), "Empty text, nothing to normalize");
}