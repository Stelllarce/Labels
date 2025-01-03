#pragma once
#include "labels/Label.hpp"
#include <iostream>
#include <sstream>

const std::string LABEL_PREFIX = "Here is a label: ";

class LabelPrinter {
public:
    static void print(const Label& label, std::ostream& output = std::cout);
    static void printWithHelpText(const HelpLabel label, std::ostream& output = std::cout);
};