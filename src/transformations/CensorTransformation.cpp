#include "CensorTransformation.hpp"

CensorTransformation::CensorTransformation(const std::string& to_censor) : to_censor(to_censor) {}

std::string CensorTransformation::transform(const std::string& text) const {
    if (to_censor.empty()) return text;
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to censor");

    std::string modified = text;
    size_t pos = modified.find(to_censor);

    if (pos == std::string::npos) throw std::invalid_argument("Word to censor not found");

    while (pos != std::string::npos) {
        modified.replace(pos, to_censor.size(), to_censor.size(), '*');
        pos = modified.find(to_censor, pos + to_censor.size());
    }
    return modified;
}