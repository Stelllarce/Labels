#pragma once
#include "Complication.hpp"

class HelpText : public Complication {
public:
    HelpText(const std::string& text);
    std::string getComplicationInformation() const override;
private:
    std::string text;
};