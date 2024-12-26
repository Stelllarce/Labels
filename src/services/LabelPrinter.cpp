#include "LabelPrinter.hpp"

void LabelPrinter::print(const Label& label, std::ostream& output) const {
    output << LABEL_PREFIX << label.getText() << std::endl;
}