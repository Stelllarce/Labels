#include "CensorTransformation.hpp"

/**
 * @param to_censor string or substring to be censored
 */
CensorTransformation::CensorTransformation(const std::string& to_censor) : to_censor(to_censor) {}

/**
 * @brief replaces the substring that matches with the string inside the class
 * with one '*' symbol for each character
 * @param text to be modified 
 * @return text with censored substrings
 * @returns the text unmodified if text is empty or the word is not found
 */
std::string CensorTransformation::transform(const std::string& text) const {
    if (to_censor.empty() || text.empty()) return text;

    std::string modified = text;
    size_t pos = modified.find(to_censor);

    while (pos != std::string::npos) {
        modified.replace(pos, to_censor.size(), to_censor.size(), '*');
        pos = modified.find(to_censor, pos + to_censor.size());
    }
    return modified;
}

bool CensorTransformation::operator==(const TextTransformation& other) const {
    if (const CensorTransformation* derived = dynamic_cast<const CensorTransformation*>(&other)) {
        return derived->to_censor == to_censor;
    }
    return false;
}