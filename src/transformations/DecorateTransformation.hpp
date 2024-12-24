#pragma once
#include "TextTransformation.hpp"

class DecorateTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
};