#include "LeftTrimTransformation.hpp"

/**
 * @return text with leftmost whitespace characters removed
 * @returns the text unmodified if text is empty
 */
std::string LeftTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;

    size_t start = 0;
    while (std::isspace(text[start]) && start++ < text.size());
    return text.substr(start);
}

bool LeftTrimTransformation::operator==(const TextTransformation& other) const {
    return dynamic_cast<const LeftTrimTransformation*>(&other) != nullptr;
}