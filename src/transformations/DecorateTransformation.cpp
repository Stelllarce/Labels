#include "DecorateTransformation.hpp"

std::string DecorateTransformation::transform(const std::string& text) const {
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to decorate");
    return "-={ " + text + " }=-";
}