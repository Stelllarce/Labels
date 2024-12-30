#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, std::unique_ptr<Color> color, std::unique_ptr<Font> font) : SimpleLabel(value), color(std::move(color)), font(std::move(font)) {}

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
    return color->getColor();
}

/**
 * @return name and size of font
 */
std::string RichLabel::getFontInfo() const {
    return font->getName() + " " + std::to_string(font->getSize());
}