#pragma once
#include <string>

class Label {
public:
    virtual std::string getText() const = 0;
    virtual std::string getDetails() const = 0;
    virtual ~Label() = default;
};