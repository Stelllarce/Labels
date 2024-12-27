#pragma once
#include "Label.hpp"

class SimpleLabel : public Label {
public:
    SimpleLabel(const std::string& value);
    std::string getText() const override;
    std::string getDetails() const override;
private:
    std::string value;
};