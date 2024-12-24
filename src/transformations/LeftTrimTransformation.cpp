#include "LeftTrimTransformation.hpp"

std::string LeftTrimTransformation::transform(const std::string& text) const {
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to trim");

    size_t start = 0;
    while (std::isspace(text[start]) && start++ < text.size());
    return text.substr(start);
}
