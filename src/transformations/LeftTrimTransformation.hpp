#pragma once
#include "TextTransformation.hpp"
/**
 * @class concrete class that removes the leftmost 
 * whitespace characters from the text
 */
class LeftTrimTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;
};