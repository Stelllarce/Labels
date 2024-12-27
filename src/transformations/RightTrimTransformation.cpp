#include "RightTrimTransformation.hpp"

std::string RightTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    
    std::string modified = text;
    while (!modified.empty() && std::isspace(modified.back())) {
        modified.pop_back();
    }
    return modified;
}