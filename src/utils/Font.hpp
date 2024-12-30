#pragma once
#include <string>

/**
 * @interface represents a font
 */
class Font {
public:
    virtual std::string getName() const = 0;
    virtual unsigned getSize() const = 0;
    virtual ~Font() = default;
};