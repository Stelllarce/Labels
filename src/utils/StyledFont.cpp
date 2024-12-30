#include "StyledFont.hpp"

/**
 * @param name of the font
 * @param size of the font
 * @throws std::invalid_argument if size is 0 or greater than MAX_FONT_SIZE
 * @throws std::invalid_argument if name is empty
 * @see MAX_FONT_SIZE
 */
StyledFont::StyledFont(const std::string& name, unsigned size) : name(name), size(size) {
    if (size == 0) throw std::invalid_argument("Font size cannot be 0");
    if (size > MAX_FONT_SIZE) throw std::invalid_argument("Font size cannot be greater than " + std::to_string(MAX_FONT_SIZE));
    if (name.empty()) throw std::invalid_argument("Font name cannot be empty");
}

/**
 * @return the name of the font
 */
std::string StyledFont::getName() const {
    return name;
}

/**
 * @return the size of the font
 */
unsigned StyledFont::getSize() const {
    return size;
}