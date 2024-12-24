#include "Color.hpp"

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
    color = (r << 16) | (g << 8) | b;
}

Color::Color(uint32_t hex_color) : color(hex_color) {
    if (hex_color > MAX_COLOR) throw std::invalid_argument("Color value cannot be greater than " + std::to_string(MAX_COLOR));
}

uint32_t Color::getColor() const {
    return color;
}