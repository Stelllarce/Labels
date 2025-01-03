#pragma once
#include <cstdint>
#include <string>
#include <sstream>
#include "Color.hpp"

/**
 * @class represents a color in RGB format
 */
class HexColor : public Color {
public:
    HexColor(uint8_t r, uint8_t g, uint8_t b);
    HexColor(uint32_t hex_color);
    std::string getColor() const;
    std::string getComplicationInformation() const override;

private:
    uint32_t color;
    static constexpr unsigned MAX_COLOR = 0xFFFFFF;
};