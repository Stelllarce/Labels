#pragma once
#include "TextTransformation.hpp"

/**
 * @class concrete class that adds "-={  }=-" around the text
 */
class DecorateTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;
};