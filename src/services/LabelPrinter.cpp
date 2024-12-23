#include "LabelPrinter.hpp"

void LabelPrinter::print(const Label& label, std::ostringstream* output) const {
    *output << label.getText() << std::endl;
    std::cout << label.getText() << std::endl;
}