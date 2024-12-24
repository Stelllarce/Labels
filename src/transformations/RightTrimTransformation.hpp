#pragma once 
#include "TextTransformation.hpp"

class RightTrimTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
};