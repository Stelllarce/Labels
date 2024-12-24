#pragma once
#include "TextTransformation.hpp"

class CensorTransformation : public TextTransformation {
public:
    CensorTransformation(const std::string& to_censor);
    std::string transform(const std::string& text) const override;
private:
    std::string to_censor;
};