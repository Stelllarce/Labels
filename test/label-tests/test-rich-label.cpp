#include "catch2/catch_all.hpp"
#include "labels/RichLabel.hpp"

TEST_CASE("Non-empty string, rgb ctor", "[RichLabel]") {
    Font font("Arial", 12);
    Color color(255, 0, 0);
    RichLabel label("Design Patterns", color, font);
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getColor() == 0xFF0000);
    REQUIRE(label.getFontInfo() == "Arial 12");
}

TEST_CASE("Non-empty string, hex ctor, implicit casting", "[RichLabel]") {
    Font font("Arial", 12);
    RichLabel label("Design Patterns", 0x00FF00, font);
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getColor() == 0x00FF00);
    REQUIRE(label.getFontInfo() == "Arial 12");
}