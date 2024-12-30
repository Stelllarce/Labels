#include "NormalizeSpaceTransformation.hpp"

/**
 * @return text with all whitespace characters replaced with a single space
 * @returns the text unmodified if text is empty
 */
std::string NormalizeSpaceTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    
    std::string modified;
    bool first_space = false;
    for (char c : text) {
        if (std::isspace(c)) {
            if (!first_space) {
                first_space = true;
                modified += ' ';
            }
        } 
        else {
            first_space = false;
            modified += c;
        }
    }    
    return modified;
}

bool NormalizeSpaceTransformation::operator==(const TextTransformation& other) const {
    return dynamic_cast<const NormalizeSpaceTransformation*>(&other) != nullptr;
}