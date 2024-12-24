#include "catch2/catch_all.hpp"
#include "transformations/ReplaceTransformation.hpp"

TEST_CASE("Single occurance replacement", "[ReplaceTransformation]") {
    ReplaceTransformation replace("fun", "boring");
    REQUIRE(replace.transform("design patterns are fun") == "design patterns are boring");
}

TEST_CASE("Multiple occurances replacement", "[ReplaceTransformation]") {
    ReplaceTransformation replace("nibba", "friend");
    REQUIRE(replace.transform("Hey, nibba, what up, my nibba") == "Hey, friend, what up, my friend");
}

TEST_CASE("Word to replace is contained within a word", "[ReplaceTransformation]") {
    ReplaceTransformation replace("bb", "xx");
    REQUIRE(replace.transform("Hey, nibba, what up, my nibba") == "Hey, nixxa, what up, my nixxa");
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

TEST_CASE("Replacement is empty, throws", "[ReplaceTransformation]") {
    REQUIRE_THROWS_WITH(ReplaceTransformation("fun", ""), "No replacement given");
}