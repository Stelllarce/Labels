#pragma once
#include "TextTransformation.hpp"

/**
 * @class class that replaces all occurrences of a string with another string
 */
class ReplaceTransformation : public TextTransformation {
public:
    ReplaceTransformation(const std::string& to_replace, const std::string& replacement);
    std::string transform(const std::string& text) const override;

private:
    std::string to_replace;
    std::string replacement;
};