#pragma once
#include "SimpleLabel.hpp"
#include "utils/Font.hpp"
#include "utils/Color.hpp"
#include <cstdint>

class RichLabel : public SimpleLabel {
public:
    RichLabel(const std::string& value, const Color& color, const Font& font);
    std::string getText() const override;
    std::string getFontInfo() const;
    uint32_t getColor() const;
private:
    Font font;
    Color color;    
    
    static constexpr unsigned MAX_COLOR = 0xFFFFFF;
};