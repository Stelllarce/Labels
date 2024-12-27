#include "DecorateTransformation.hpp"

std::string DecorateTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    return "-={ " + text + " }=-";
}