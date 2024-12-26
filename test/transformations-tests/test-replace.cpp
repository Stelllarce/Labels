#include "catch2/catch_all.hpp"
#include "transformations/ReplaceTransformation.hpp"

TEST_CASE("Single occurance replacement", "[ReplaceTransformation]") {
    ReplaceTransformation replace("fun", "boring");
    REQUIRE(replace.transform("design patterns are fun") == "design patterns are boring");
}

TEST_CASE("Multiple occurances replacement", "[ReplaceTransformation]") {
    ReplaceTransformation replace("homie", "friend");
    REQUIRE(replace.transform("Hey, homie, what up, my homie") == "Hey, friend, what up, my friend");
}

TEST_CASE("Word to replace is contained within a word", "[ReplaceTransformation]") {
    ReplaceTransformation replace("i", "o");
    REQUIRE(replace.transform("Hey, homie, what up, my homie") == "Hey, homoe, what up, my homoe");
}

TEST_CASE("Replace substring within a word, replacement is longer than original", "[ReplaceTransformation]") {
    ReplaceTransformation replace("omi", "fasollasido");
    REQUIRE(replace.transform("Hey, homie, what up, my homie") == "Hey, hfasollasidoe, what up, my hfasollasidoe");
}

TEST_CASE("Replace substring within a word, replacement is shorter than original", "[ReplaceTransformation]") {
    ReplaceTransformation replace("omi", "a");
    REQUIRE(replace.transform("Hey, homie, what up, my homie") == "Hey, hae, what up, my hae");
}

TEST_CASE("Replace with empty string", "[ReplaceTransformation]") {
    ReplaceTransformation replace("homie", "");
    REQUIRE(replace.transform("Hey, homie, what up, my homie") == "Hey, , what up, my ");
}

TEST_CASE("Word to replace not found, throws", "[ReplaceTransformation]") {
    ReplaceTransformation replace("boring", "fun");
    REQUIRE_THROWS_WITH(replace.transform("design patterns are fun"), "Word to replace not found");
}

TEST_CASE("Empty text, throws", "[ReplaceTransformation]") {
    ReplaceTransformation replace("boring", "fun");
    REQUIRE_THROWS_WITH(replace.transform(""), "Empty text, nothing to replace");
}

TEST_CASE("Nothing to replace, throws", "[ReplaceTransformation]") {
    REQUIRE_THROWS_WITH(ReplaceTransformation("", "fun"), "No argument for replacement given");
}