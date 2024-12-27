#include "LeftTrimTransformation.hpp"

std::string LeftTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;

    size_t start = 0;
    while (std::isspace(text[start]) && start++ < text.size());
    return text.substr(start);
}
