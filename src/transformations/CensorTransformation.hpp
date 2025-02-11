#pragma once
#include "TextTransformation.hpp"

/**
 * @class replaces every symbol in a
 * string with '*'. the string to be replaced is passed inside the ctor
 */
class CensorTransformation : public TextTransformation {
public:
    CensorTransformation(const std::string& to_censor);
    std::string transform(const std::string& text) const override;
    std::string getCensorWord() const;
    bool operator==(const TextTransformation& other) const override;
    std::unique_ptr<TextTransformation> clone() const override;
private:
    std::string to_censor;
};