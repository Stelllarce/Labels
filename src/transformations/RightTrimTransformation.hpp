#pragma once 
#include "TextTransformation.hpp"

/**
 * @class that removes the rightmost whitespace characters from the text
 */
class RightTrimTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;
    std::unique_ptr<TextTransformation> clone() const override;
};