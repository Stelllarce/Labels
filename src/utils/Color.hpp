#pragma once
#include <string>
#include "Complication.hpp"

/**
 * @interface represents a color
 */
class Color : public Complication {
public:
    virtual ~Color() = default;
protected:
    virtual std::string getColor() const = 0;
};