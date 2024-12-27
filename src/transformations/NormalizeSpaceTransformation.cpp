#include "NormalizeSpaceTransformation.hpp"

std::string NormalizeSpaceTransformation::transform(const std::string& text) const {
    if (text.empty()) return text;
    
    std::string modified;
    bool first_space = false;
    for (char c : text) {
        if (std::isspace(c)) {
            if (!first_space) {
                first_space = true;
                modified += ' ';
            }
        } 
        else {
            first_space = false;
            modified += c;
        }
    }    
    return modified;
}