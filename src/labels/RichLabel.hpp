#pragma once
#include "SimpleLabel.hpp"
#include "utils/HexColor.hpp"
#include "utils/StyledFont.hpp"
#include <cstdint>
#include <memory>

/**
 * @class is an extention of the simple label
 * adds color and font
 */
class RichLabel : public SimpleLabel {
public:
    RichLabel(const std::string& value, std::unique_ptr<Color> color, std::unique_ptr<Font> font);
    std::string getText() const override;
    std::string getFontInfo() const;
    std::string getColorString() const;
    std::string getDetails() const override;
private:
    std::unique_ptr<Font> font;
    std::unique_ptr<Color> color;    
};