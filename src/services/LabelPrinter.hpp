#pragma once
#include "labels/SimpleLabel.hpp"
#include <iostream>
#include <sstream>

class LabelPrinter {
public:
    void print(const Label& label, std::ostringstream* output = nullptr) const;
};