#pragma once
#include "labels/Label.hpp"
#include <iostream>
#include <sstream>

const std::string LABEL_PREFIX = "Here is a label: ";

class LabelPrinter {
public:
    void print(const Label& label, std::ostream& output = std::cout) const;
};