#include "catch2/catch_all.hpp"
#include "labels/RichLabel.hpp"

TEST_CASE("Non-empty string, rgb ctor", "[RichLabel]") {
    RichLabel label("Design Patterns", "#FF0000", "Arial:12");
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getFontInfo() == "Arial:12");
    REQUIRE(label.getColorString() == "#FF0000");
}

TEST_CASE("Non-empty string, hex ctor, implicit casting", "[RichLabel]") {
    RichLabel label("Design Patterns", "#00FF00", "Arial:12");
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getFontInfo() == "Arial:12");
    REQUIRE(label.getColorString() == "#00FF00");
}

TEST_CASE("Adding help text to rich label", "[RichLabel]") {
    RichLabel label("Design Patterns", "#FF0000", "Arial:12", std::make_unique<HelpText>("This is a label with color and font."));
    
    REQUIRE(label.getHelpText() == "This is a label with color and font.");
}