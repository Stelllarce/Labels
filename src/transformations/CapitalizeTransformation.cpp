#include "CapitalizeTransformation.hpp"

std::string CapitalizeTransformation::transform(const std::string& text) const {
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to capitalize");
    std::string modified = text;
    if (!modified.empty() && isalpha(modified[0])) {
        modified[0] = std::toupper(modified[0]);
    }
    return modified;
}