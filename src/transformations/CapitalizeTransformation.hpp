#pragma once
#include "TextTransformation.hpp"

/**
 * @class capitalizes the first
 * symbol of the string if it's a letter
 */
class CapitalizeTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;
    std::unique_ptr<TextTransformation> clone() const override;
};