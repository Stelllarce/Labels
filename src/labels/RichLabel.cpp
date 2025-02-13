#include "RichLabel.hpp"

RichLabel::RichLabel(const std::string& value, 
    const std::string& color, 
    const std::string& font, 
    std::unique_ptr<HelpText> complication) :
    SimpleLabel(value, std::move(complication)), color(color), font(font) {}

RichLabel::RichLabel(const std::string& value, 
    const std::string& color,
    const std::string& font) : 
    SimpleLabel(value), color(color), font(font) {}

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
    return color;
}

/**
 * @return name and size of font
 */
std::string RichLabel::getFontInfo() const {
    return font;
}

std::string RichLabel::getHelpText() const {
    return getComplication()->getComplicationInformation();
}

void RichLabel::setHelpText(const std::string& help_txt) {
    SimpleLabel::setHelpText(help_txt);
}