#include "LabelDecoratorBase.hpp"

LabelDecoratorBase::LabelDecoratorBase(std::shared_ptr<Label> label) : label(label) {}

/**
 * @return the text of the label
 */
std::string LabelDecoratorBase::getText() const {
    return label->getText();
}

/**
 * @return additional information about the label
 */
std::string LabelDecoratorBase::getDetails() const {
    return label->getDetails();
}
