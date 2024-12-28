#pragma once
#include <string>
#include <stdexcept>

/**
 * @interface for all text transformations
 */
class TextTransformation {
public:
    virtual std::string transform(const std::string& text) const = 0;
    virtual ~TextTransformation() = default;
};