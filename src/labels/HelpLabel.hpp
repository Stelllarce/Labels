#pragma once
#include "Label.hpp"
#include "HelpLabel.hpp"
#include <string>

class HelpLabel : public Label {
public:
    std::string getHelpText() const;
private:
    std::string help_field;  
};
