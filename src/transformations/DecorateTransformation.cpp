#include "DecorateTransformation.hpp"

/**
 * @return decorated text
 * @returns the text unmodified if text is empty
 */
std::string DecorateTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    return "-={ " + text + " }=-";
}