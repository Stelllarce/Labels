#include "HelpText.hpp"

HelpText::HelpText(const std::string& text) : text(text) {}

std::string HelpText::getComplicationInformation() const {
    return text;
}