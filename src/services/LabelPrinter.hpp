#pragma once
#include "labels/Label.hpp"
#include <iostream>
#include <sstream>


class LabelPrinter {
    static const char* const LABEL_PREFIX;
    static const char* const HELP_PREFIX;   
public:
    static void print(const Label& label, std::ostream& output = std::cout);
    static void printWithHelpText(const Label& label, std::ostream& output = std::cout);
}; 
