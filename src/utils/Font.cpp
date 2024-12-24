#include "Font.hpp"

Font::Font(const std::string& name, unsigned size) : name(name), size(size) {
    if (size == 0) throw std::invalid_argument("Font size cannot be 0");
    if (size > MAX_FONT_SIZE) throw std::invalid_argument("Font size cannot be greater than " + std::to_string(MAX_FONT_SIZE));
    if (name.empty()) throw std::invalid_argument("Font name cannot be empty");
}

std::string Font::getName() const {
    return name;
}

unsigned Font::getSize() const {
    return size;
}