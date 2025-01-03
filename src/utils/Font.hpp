#pragma once
#include <string>
#include "Complication.hpp"

/**
 * @interface represents a font
 */
class Font : public Complication {
public:
    virtual ~Font() = default;
protected:
    virtual std::string getName() const = 0;
    virtual unsigned getSize() const = 0;
};