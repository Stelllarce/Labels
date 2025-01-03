#include "LabelPrinter.hpp"

void LabelPrinter::print(const Label& label, std::ostream& output) {
    output << LABEL_PREFIX << label.getText() << label.getDetails() << std::endl;
}

void LabelPrinter::printWithHelpText(const HelpLabel label, std::ostream& output = std::cout) {
    print(label, output);
    output << label.getHelpText() << std::endl;
}
