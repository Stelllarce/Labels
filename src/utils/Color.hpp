#pragma once
#include <cstdint>
#include <string>
#include <sstream>

class Color {
public:
    Color(uint8_t r, uint8_t g, uint8_t b);
    Color(uint32_t hex_color);
    uint32_t getColor() const;
    std::string hexColorToString() const;

    static constexpr unsigned MAX_COLOR = 0xFFFFFF;
private:
    uint32_t color;
};