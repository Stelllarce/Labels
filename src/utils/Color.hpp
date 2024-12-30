#pragma once
#include <string>

/**
 * @interface represents a color
 */
class Color {
public:
    virtual std::string getColor() const = 0;
    virtual ~Color() = default;
};