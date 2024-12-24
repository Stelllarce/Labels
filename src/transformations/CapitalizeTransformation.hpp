#pragma once
#include "TextTransformation.hpp"

class CapitalizeTransformation : public TextTransformation {
public:
    std::string transform(const std::string& text) const override;
};