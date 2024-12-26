#include "LabelDecoratorBase.hpp"

LabelDecoratorBase::LabelDecoratorBase(std::shared_ptr<Label> label) : label(label) {}

std::string LabelDecoratorBase::getText() const {
    return label->getText();
}
