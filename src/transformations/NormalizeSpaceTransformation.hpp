#pragma once
#include "TextTransformation.hpp"

/**
 * @class class that reduces all consecutive spaeces
 * inside the text to a single space
 */
class NormalizeSpaceTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;
    std::unique_ptr<TextTransformation> clone() const override;
};

