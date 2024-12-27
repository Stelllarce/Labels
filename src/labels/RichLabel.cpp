#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, const Color& color, const Font& font) : SimpleLabel(value), font(font), color(color) {}

std::string RichLabel::getText() const {
    return SimpleLabel::getText();
}

std::string RichLabel::getDetails() const {
    return " " + getFontInfo() + " " + getColorString();
}

std::string RichLabel::getColorString() const {
    return color.hexColorToString();
}

std::string RichLabel::getFontInfo() const {
    return font.getName() + " " + std::to_string(font.getSize());
}