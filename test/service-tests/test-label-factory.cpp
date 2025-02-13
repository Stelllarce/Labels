#include "catch2/catch_all.hpp"
#include "services/LabelFactory.hpp"
#include <sstream>

SCENARIO("Creating labels using LabelFactory") {
    GIVEN("A request to create different types of labels") {
        WHEN("Creating a simple label") {
            auto label = LabelFactory::createLabel("simple", "Hello World");

            THEN("The label should be created with correct text") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Hello World");
                REQUIRE(label->getHelpText().empty());
            }
        }

        WHEN("Creating a simple label with help text") {
            auto label = LabelFactory::createLabel(
                "simple", 
                "Hello World",
                "helptext:This_is_help_text"
            );

            THEN("The label should be created with correct text and help text") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Hello World");
                REQUIRE(label->getHelpText() == "This_is_help_text");
            }
        }

        WHEN("Creating a rich label with valid options") {
            std::string options = "color:#FF0000 font:Arial font_size:12";
            auto label = LabelFactory::createLabel("rich", "Styled Text", options);

            THEN("The label should be created with correct properties") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Styled Text");
                auto* rich_label = dynamic_cast<RichLabel*>(label.get());
                REQUIRE(rich_label != nullptr);
                REQUIRE(rich_label->getColorString() == "#FF0000");
                REQUIRE(rich_label->getFontInfo() == "Arial:12");
                REQUIRE(label->getHelpText().empty());
            }
        }

        WHEN("Creating a rich label with help text") {
            std::string options = "color:#FF0000 font:Arial font_size:12 helptext:Rich_Label_Help";
            auto label = LabelFactory::createLabel("rich", "Styled Text", options);

            THEN("The label should be created with correct properties and help text") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Styled Text");
                auto* rich_label = dynamic_cast<RichLabel*>(label.get());
                REQUIRE(rich_label != nullptr);
                REQUIRE(rich_label->getColorString() == "#FF0000");
                REQUIRE(rich_label->getFontInfo() == "Arial:12");
                REQUIRE(label->getHelpText() == "Rich_Label_Help");
            }
        }

        WHEN("Creating a rich label with missing options") {
            std::string options = "color:#FF0000 helptext:Help_Text";  // Missing font and font_size
            auto label = LabelFactory::createLabel("rich", "Styled Text", options);

            THEN("The creation should fail") {
                REQUIRE(label == nullptr);
            }
        }

        WHEN("Creating a basic custom label") {
            auto label = LabelFactory::createLabel("custom", "Test Label");

            THEN("The label should be created with correct text") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Test Label");
                REQUIRE(label->getDetails() == "1 requests");
                REQUIRE(label->getHelpText().empty());
            }
        }

        WHEN("Creating a custom label with help text") {
            auto label = LabelFactory::createLabel(
                "custom", 
                "Custom Label Text",
                "helptext:This_is_help_text"
            );

            THEN("The label should be created with correct text and help text") {
                REQUIRE(label != nullptr);
                REQUIRE(label->getText() == "Custom Label Text");
                REQUIRE(label->getHelpText() == "This_is_help_text");
                REQUIRE(label->getDetails() == "1 requests");
            }
        }

        WHEN("Creating a custom label with multiple requests") {
            auto label = LabelFactory::createLabel("custom", "Test Label");
            REQUIRE(label != nullptr);

            THEN("Request count should increment") {
                REQUIRE(label->getText() == "Test Label");  // First request
                REQUIRE(label->getDetails() == "1 requests");
                REQUIRE(label->getText() == "Test Label");  // Second request
                REQUIRE(label->getDetails() == "2 requests");
            }
        }

        WHEN("Attempting to create a label with invalid type") {
            auto label = LabelFactory::createLabel("invalid_type", "Some Text");

            THEN("The creation should fail") {
                REQUIRE(label == nullptr);
            }
        }
    }
}