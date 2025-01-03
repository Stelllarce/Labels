#pragma once
#include "Font.hpp"
#include <stdexcept>

/**
 * @class represents a font with a name and size
 */
class StyledFont : public Font {
public:
    StyledFont(const std::string& name, unsigned size);
    std::string getName() const override;
    std::string getComplicationInformation() const override;
    unsigned getSize() const;
private:
    unsigned size;
    std::string name;

    static const unsigned MAX_FONT_SIZE = 1638;
};