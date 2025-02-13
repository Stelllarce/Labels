#include "SimpleLabel.hpp"

SimpleLabel::SimpleLabel(const std::string& value, 
    std::unique_ptr<Complication> complication) : 
    Label(std::move(complication)), 
    value(value) {}


SimpleLabel::SimpleLabel(const std::string& value) : value(value) {}

/**
 * @return the text of the label
 */
std::string SimpleLabel::getText() const {
    return value;
}

/**
 * @return empty string
 */
std::string SimpleLabel::getDetails() const {
    return "";
}

std::string SimpleLabel::getHelpText() const {
    return getComplication()->getComplicationInformation();
}

void SimpleLabel::setHelpText(const std::string& help_txt) {
    complication = std::make_unique<HelpText>(help_txt);
}