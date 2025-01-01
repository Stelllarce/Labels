#include "CustomLabel.hpp"

/**
 * @brief initializes label if its empty by giving it a text through an input stream
 */
std::shared_ptr<SimpleLabel> CustomLabel::getLabel() const {
    if(label == nullptr) {
        std::string text;
        #ifndef UNIT_TESTING
        std::cout << "Enter text of custom lbl: ";
        #endif
        std::getline(is, text);
        label = std::make_shared<SimpleLabel>(text);
    }
    return label;
}

/**
 * @brief when requests reach more than timeout it prompts for a change of textx
 * initializes the text first time it is invoked and returns it
 */
std::string CustomLabel::getText() const {
    if(requests++ >= TIMEOUT) {
        promptChange();
    }
    return getLabel()->getText();
}

/**
 * @brief returns the number of current requests
 */
std::string CustomLabel::getDetails() const {
    return std::to_string(requests) + " requests";
}

/**
 * @brief prompts the user to change the existing text
 * if 'y' has been inputted then nullify label ptr and set requests back to 0
 */
void CustomLabel::promptChange() const {
#ifndef UNIT_TESTING
    std::cout << "Enter new text? [y|n]: ";
#endif 
    char answer;
    is.get(answer);
    is.ignore(); // ignore newline

    if(toupper(answer) == 'Y') {
        // should behave like calling label.reset() here, so no leak
        label = nullptr;
        requests = 0;
    }
}