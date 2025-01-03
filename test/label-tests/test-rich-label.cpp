#include "catch2/catch_all.hpp"
#include "labels/RichLabel.hpp"

TEST_CASE("Non-empty string, rgb ctor", "[RichLabel]") {
    std::unique_ptr<Color> color = std::make_unique<HexColor>(0xFF0000);
    std::unique_ptr<Font> font = std::make_unique<StyledFont>("Arial", 12);
    RichLabel label("Design Patterns", std::move(color), std::move(font));
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getFontInfo() == "Arial 12");
    REQUIRE(label.getColorString() == "0xFF0000");
}

TEST_CASE("Non-empty string, hex ctor, implicit casting", "[RichLabel]") {
    std::unique_ptr<Color> color = std::make_unique<HexColor>(0xFF00);
    std::unique_ptr<Font> font = std::make_unique<StyledFont>("Arial", 12);

    RichLabel label("Design Patterns", std::move(color), std::move(font));
    
    REQUIRE(label.getText() == "Design Patterns");
    REQUIRE(label.getFontInfo() == "Arial 12");
    REQUIRE(label.getColorString() == "0xFF00");
}

TEST_CASE("Adding help text to rich label", "[RichLabel]") {
    std::unique_ptr<Color> color = std::make_unique<HexColor>(0xFF0000);
    std::unique_ptr<Font> font = std::make_unique<StyledFont>("Arial", 12);
    RichLabel label("Design Patterns", std::move(color), std::move(font), std::make_unique<HelpText>("This is a label with color and font."));
    
    REQUIRE(label.getHelpText() == "This is a label with color and font.");
}