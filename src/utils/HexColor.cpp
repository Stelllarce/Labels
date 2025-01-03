#include "HexColor.hpp"

/**
 * @brief constructs a color from RGB values, using bit shift
 * @param r red color value
 * @param g green color value
 * @param b blue color value
 */
HexColor::HexColor(uint8_t r, uint8_t g, uint8_t b) {
    color = (r << 16) | (g << 8) | b;
}

/**
 * @brief constructs a color from a hex value
 * @param hex_color hex color value
 * @throws std::invalid_argument if hex_color is greater than 0xFFFFFF
 */
HexColor::HexColor(uint32_t hex_color) : color(hex_color) {
    if (hex_color > MAX_COLOR) throw std::invalid_argument("HexColor value cannot be greater than " + std::to_string(MAX_COLOR));
}

/**
 * @return the color in hex format 
 */
std::string HexColor::getColor() const {
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << color;
    return ss.str();
}

/**
 * @return the color in hex format
 */
std::string HexColor::getComplicationInformation() const {
    return getColor();
}