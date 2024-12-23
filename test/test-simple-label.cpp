#include "catch2/catch_all.hpp"
#include "labels/SimpleLabel.hpp"

TEST_CASE("SimpleLabel test", "[SimpleLabel]") {
	SECTION("SimpleLabel with non-empty string") {
		SimpleLabel label("Design Patterns");
		REQUIRE(label.getText() == "Design Patterns");
	}

	SECTION("SimpleLabel with empty string") {
		SimpleLabel label("");
		REQUIRE(label.getText() == "");
	}
}