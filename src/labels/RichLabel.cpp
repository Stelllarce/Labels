#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, 
    std::unique_ptr<Color> color, 
    std::unique_ptr<Font> font, 
    std::unique_ptr<HelpText> complication) :
    SimpleLabel(value, std::move(complication)), color(std::move(color)), font(std::move(font)) {}

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
    return color->getComplicationInformation();
}

/**
 * @return name and size of font
 */
std::string RichLabel::getFontInfo() const {
    return font->getComplicationInformation();
}

std::string RichLabel::getHelpText() const {
    return getComplication()->getComplicationInformation();
}