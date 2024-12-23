#pragma once
#include <string>
#include <stdexcept>

class TextTransformation {
public:
    virtual std::string transform(const std::string& text) const = 0;
    virtual ~TextTransformation() = default;
};