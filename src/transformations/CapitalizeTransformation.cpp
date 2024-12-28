#include "CapitalizeTransformation.hpp"

/**
 * @brief capitalize first symbol of the string if it's a string
 * @return a modified version of the string
 */
std::string CapitalizeTransformation::transform(const std::string& text) const {
    std::string modified = text;
    if (!modified.empty() && isalpha(modified[0])) {
        modified[0] = std::toupper(modified[0]);
    }
    return modified;
}