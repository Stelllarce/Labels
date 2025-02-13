#pragma once
#include "SimpleLabel.hpp"
#include "utils/HelpText.hpp"
#include <cstdint>
#include <memory>

/**
 * @class is an extention of the simple label
 * adds color and font
 */
class RichLabel : public SimpleLabel {
public:
    explicit RichLabel(const std::string& value, const std::string& color, const std::string& font, std::unique_ptr<HelpText> complication);
    explicit RichLabel(const std::string& value, const std::string& color, const std::string& font);
    std::string getText() const override;
    std::string getFontInfo() const;
    std::string getColorString() const;
    std::string getDetails() const override;
    std::string getHelpText() const override;
    void setHelpText(const std::string& help_txt) override;
private:
    std::string font;
    std::string color;    
};