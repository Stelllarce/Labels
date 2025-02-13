#pragma once
#include <string>

/**
 * @interface for all complications
 */
class Complication {
public:
    virtual std::string getComplicationInformation() const = 0;
};