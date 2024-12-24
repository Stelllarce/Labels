#include "RightTrimTransformation.hpp"

std::string RightTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to trim");
    
    std::string modified = text;
    while (!modified.empty() && std::isspace(modified.back())) {
        modified.pop_back();
    }
    return modified;
}