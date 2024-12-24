#pragma once
#include "TextTransformation.hpp"

class NormalizeSpaceTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
};