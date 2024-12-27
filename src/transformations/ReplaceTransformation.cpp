#include "ReplaceTransformation.hpp"

ReplaceTransformation::ReplaceTransformation(const std::string& to_replace, const std::string& replacement) : to_replace(to_replace), replacement(replacement) {}

std::string ReplaceTransformation::transform(const std::string& text) const {
    if (text.empty() || to_replace.empty() || replacement.empty()) return text;

    std::string modified = text;
    size_t pos = modified.find(to_replace);

    if (pos == std::string::npos) throw std::invalid_argument("Word to replace not found");

    while (pos != std::string::npos) {
        modified.replace(pos, to_replace.size(), replacement);
        pos = modified.find(to_replace, pos + replacement.size());
    }
    return modified;
}