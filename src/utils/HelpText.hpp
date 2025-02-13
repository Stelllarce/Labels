#pragma once
#include "Complication.hpp"

/**
 * @class class that represents help text to be added to a label
 */
class HelpText : public Complication {
public:
    HelpText(const std::string& text);
    std::string getComplicationInformation() const override;
private:
    std::string text;
};