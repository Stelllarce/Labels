#include "ReplaceTransformation.hpp"

/**
 * @param to_replace string to be replaced
 * @param replacement string to replace with
 */
ReplaceTransformation::ReplaceTransformation(const std::string& to_replace, const std::string& replacement) : to_replace(to_replace), replacement(replacement) {}

/**
 * @brief replaces all occurrences of the string to_replace with the string replacement
 * @param text to be modified
 * @return text with replaced substrings
 * @returns the text unmodified if text is empty or the word is not found
 */
std::string ReplaceTransformation::transform(const std::string& text) const {
    if (text.empty() || to_replace.empty()) return text;

    std::string modified = text;
    size_t pos = modified.find(to_replace);

    if (pos == std::string::npos) throw std::invalid_argument("Word to replace not found");

    while (pos != std::string::npos) {
        modified.replace(pos, to_replace.size(), replacement);
        pos = modified.find(to_replace, pos + replacement.size());
    }
    return modified;
}

bool ReplaceTransformation::operator==(const TextTransformation& other) const {
    if (const ReplaceTransformation* derived = dynamic_cast<const ReplaceTransformation*>(&other)) {
        return derived->to_replace == to_replace && derived->replacement == replacement;
    }
    return false;
}