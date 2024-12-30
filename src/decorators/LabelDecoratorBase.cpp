#include "LabelDecoratorBase.hpp"

LabelDecoratorBase::LabelDecoratorBase(const std::shared_ptr<Label>& label) : label(label) {}

/**
 * @return the text of the label
 */
std::string LabelDecoratorBase::getText() const {
    if (!label) return "";
    return label->getText();
}

/**
 * @return additional information about the label
 */
std::string LabelDecoratorBase::getDetails() const {
    return label->getDetails();
}

/**
 * @brief removes a decorator from the label
 * the algoritm is a basic traversal and removal 
 * in a linked list using two pointers
 * for the current and previous node.
 * the first element of the list is the last applied decoration
 * and the last is the bare label object
 * @param l the label to remove the decorator from
 * @param to_rm the decorator to remove as an r-value
 */
std::shared_ptr<Label> LabelDecoratorBase::removeDecoratorFrom(std::shared_ptr<Label>& l, std::shared_ptr<LabelDecoratorBase>&& to_rm) {
    if (to_rm == nullptr) return l;

    std::shared_ptr<LabelDecoratorBase> prev = nullptr;
    // start with the first element in the list, being the last applied decoration
    std::shared_ptr<LabelDecoratorBase> curr = std::dynamic_pointer_cast<LabelDecoratorBase>(l);

    while (curr) {
        if (*curr == *to_rm) {
            if (prev) {
                // deletion just like in a linked list, substitute "label" with "next"
                prev->label = curr->label;
            } else {
                // in case the first element is the one to be removed
                // just make it point to the third one
                l = curr->label;
            }
            break;
        } else {
            prev = curr;
            // when trying to cast the last cell, it will give nullptr, because
            // it's a simple label, not derived from LabelDecoratorBase. 
            // So the linked list will stop at position second to last element
            // and exit the loop when the element for removal is not found
            curr = std::dynamic_pointer_cast<LabelDecoratorBase>(curr->label);
        }
    }
    return l;
}

bool LabelDecoratorBase::operator==(const LabelDecoratorBase& other) const {
    return label == other.label;
}