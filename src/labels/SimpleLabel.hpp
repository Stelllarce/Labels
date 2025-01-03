#pragma once
#include "Label.hpp"
#include "utils/HelpText.hpp"

/**
 * @class adds a text field, storing the text
 * of the label
 */
class SimpleLabel : public Label {
public:
    SimpleLabel(const std::string& value);
    SimpleLabel(const std::string& value, std::unique_ptr<HelpText> complication);
    std::string getText() const override;
    std::string getDetails() const override;
    std::string getHelpText() const override;
private:
    std::string value;
};