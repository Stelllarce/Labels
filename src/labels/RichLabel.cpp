#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, const Color& color, const Font& font) : SimpleLabel(value), font(font), color(color) {}

std::string RichLabel::getText() const {
    return SimpleLabel::getText();
}

uint32_t RichLabel::getColor() const {
    return color.getColor();
}

std::string RichLabel::getFontInfo() const {
    return font.getName() + " " + std::to_string(font.getSize());
}