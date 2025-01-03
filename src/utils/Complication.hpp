#pragma once
#include <string>

class Complication {
public:
    virtual std::string getComplicationInformation() const = 0;
};