#include "ReplaceTransformation.hpp"

ReplaceTransformation::ReplaceTransformation(const std::string& to_replace, const std::string& replacement) : to_replace(to_replace), replacement(replacement) {
    if (to_replace.empty()) throw std::invalid_argument("No argument for replacement given");
}

std::string ReplaceTransformation::transform(const std::string& text) const {
    if (text.empty()) throw std::invalid_argument("Empty text, nothing to replace");

    std::string modified = text;
    size_t pos = modified.find(to_replace);

    if (pos == std::string::npos) throw std::invalid_argument("Word to replace not found");

    while (pos != std::string::npos) {
        modified.replace(pos, to_replace.size(), replacement);
        pos = modified.find(to_replace, pos + replacement.size());
    }
    return modified;
}