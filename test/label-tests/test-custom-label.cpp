#include "catch2/catch_all.hpp"
#include "labels/CustomLabel.hpp"
#include <sstream>

SCENARIO("Making 4 requests and accepting change", "[CustomLabel]") {
    GIVEN("A custom label with initial text and future user input") {
        std::istringstream is("initial custom label text\n"
                                "y\n"
                                "new custom label text\n");
        CustomLabel label(is);
        REQUIRE(label.getText() == "initial custom label text");

        WHEN("4 requests are made and a change is accepted on the last request") {
            THEN("The text will stay the same on the second request") {
                REQUIRE(label.getText() == "initial custom label text");
                AND_THEN("The text will stay the same on the third request") {
                    REQUIRE(label.getText() == "initial custom label text");
                    AND_THEN("The text will stay the same on the fourth request") {
                        REQUIRE(label.getText() == "initial custom label text");
                        AND_THEN("Timeout will hit and the text will change on the fifth request") {
                            REQUIRE(label.getText() == "new custom label text");
                        }
                    }
                }
            }
        }
    }
}

SCENARIO("Making 4 requests and declining change", "[CustomLabel]") {
    GIVEN("A custom label with initial text and future user input") {
        std::istringstream is("initial custom label text\n"
                                "n\n");
        CustomLabel label(is);
        REQUIRE(label.getText() == "initial custom label text");

        WHEN("4 requests are made and a change is accepted on the last request") {
            THEN("The text will stay the same on the second request") {
                REQUIRE(label.getText() == "initial custom label text");
                AND_THEN("The text will stay the same on the third request") {
                    REQUIRE(label.getText() == "initial custom label text");
                    AND_THEN("The text will stay the same on the fourth request") {
                        REQUIRE(label.getText() == "initial custom label text");
                        AND_THEN("Change will be declined and the text will stay the same") {
                            REQUIRE(label.getText() == "initial custom label text");
                        }
                    }
                }
            }
        }
    }
}

TEST_CASE("Add help text to custom label", "[CustomLabel]") {
    std::istringstream is("initial custom label text\n"
                            "y\n"
                            "new custom label text\n");
    CustomLabel label(is, std::make_unique<HelpText>("This is a custom label that can be changed after 4 requests."));
    REQUIRE(label.getHelpText() == "This is a custom label that can be changed after 4 requests.");
}