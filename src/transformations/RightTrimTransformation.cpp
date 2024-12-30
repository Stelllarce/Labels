#include "RightTrimTransformation.hpp"

/**
 * @return text with rightmost whitespace characters removed
 * @returns the text unmodified if text is empty
 */
std::string RightTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    
    std::string modified = text;
    while (!modified.empty() && std::isspace(modified.back())) {
        modified.pop_back();
    }
    return modified;
}

bool RightTrimTransformation::operator==(const TextTransformation& other) const {
    return dynamic_cast<const RightTrimTransformation*>(&other) != nullptr;
}