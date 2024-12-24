#pragma once
#include <string>
#include <stdexcept>

class Font {
public:
    Font(const std::string& name, unsigned size);
    std::string getName() const;
    unsigned getSize() const;
private:
    unsigned size;
    std::string name;

    static const unsigned MAX_FONT_SIZE = 1638;
};