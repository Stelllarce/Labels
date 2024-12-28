#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, const Color& color, const Font& font) : SimpleLabel(value), font(font), color(color) {}

/**
 * @return text of the label
 */
std::string RichLabel::getText() const {
    return SimpleLabel::getText();
}

/**
 * @return font info and string color
 */
std::string RichLabel::getDetails() const {
    return " " + getFontInfo() + " " + getColorString();
}

/**
 * @return color hex as string
 */
std::string RichLabel::getColorString() const {
    return color.hexColorToString();
}

/**
 * @return name and size of font
 */
std::string RichLabel::getFontInfo() const {
    return font.getName() + " " + std::to_string(font.getSize());
}