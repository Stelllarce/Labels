#include "LabelPrinter.hpp"

const char* const LabelPrinter::LABEL_PREFIX = "Here is a label: ";
const char* const LabelPrinter::HELP_PREFIX = "Some help information about this label: ";  

void LabelPrinter::print(const Label& label, std::ostream& output) {
    output << LABEL_PREFIX << label.getText() << label.getDetails() << std::endl;
}

void LabelPrinter::printWithHelpText(const Label& label, std::ostream& output) {
    print(label, output);
    output << HELP_PREFIX << label.getHelpText() << std::endl;
}