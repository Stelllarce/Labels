#include "catch2/catch_all.hpp"
#include "transformations/CensorTransformation.hpp"

TEST_CASE("Single occurance censoring", "[CensorTransformation]") {
    CensorTransformation censor("fun");
    REQUIRE(censor.transform("design patterns are fun") == "design patterns are ***");
}

TEST_CASE("Multiple occurances censoring", "[CensorTransformation]") {
    CensorTransformation censor("nibba");
    REQUIRE(censor.transform("Hey, nibba, what up, my nibba") == "Hey, *****, what up, my *****");
}

TEST_CASE("Word to censor is contained in a word", "[CensorTransformation]") {
    CensorTransformation censor("bb");
    REQUIRE(censor.transform("Hey, nibba, what up, my nibba") == "Hey, ni**a, what up, my ni**a");
}

TEST_CASE("Edge case with same letters", "[CensorTransformation]") {
    CensorTransformation censor("aa");
    REQUIRE(censor.transform("aaaaa") == "****a");
}

TEST_CASE("Censor word not found, throws", "[CensorTransformation]") {
    CensorTransformation censor("boring");
    REQUIRE_THROWS_WITH(censor.transform("design patterns are fun"), "Word to censor not found");
}

TEST_CASE("Empty text, throws", "[CensorTransformation]") {
    CensorTransformation censor("boring");
    REQUIRE_THROWS_WITH(censor.transform(""), "Empty text, nothing to censor");
}

TEST_CASE("Nothing to censor, should stay the same", "[CensorTransformation]") {
    CensorTransformation censor("");
    REQUIRE(censor.transform("design patterns are fun") == "design patterns are fun");
}