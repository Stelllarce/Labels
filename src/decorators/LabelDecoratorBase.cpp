#include "LabelDecoratorBase.hpp"
#include <utility>

LabelDecoratorBase::LabelDecoratorBase(std::unique_ptr<Label> label)
    : label(std::move(label)) {}

std::string LabelDecoratorBase::getText() const {
    if (!label)
        return "";
    return label->getText();
}

std::string LabelDecoratorBase::getDetails() const {
    return label->getDetails();
}

std::unique_ptr<Label> LabelDecoratorBase::removeDecoratorFrom(
    std::unique_ptr<Label> l,
    std::unique_ptr<LabelDecoratorBase> to_rm)
{
    if (!to_rm || !l)
        return std::move(l);

    // If the current node is the one to remove and it's a decorator
    auto* current_decorator = dynamic_cast<LabelDecoratorBase*>(l.get());
    if (current_decorator && *current_decorator == *to_rm) {
        // Move the child label out before the current node is destroyed
        return std::move(current_decorator->label);
    }

    // If the current node is a decorator but not the one to remove,
    // recursively process its child
    if (current_decorator) {
        current_decorator->label = removeDecoratorFrom(
            std::move(current_decorator->label),
            std::move(to_rm)
        );
    }

    return std::move(l);
}

bool LabelDecoratorBase::operator==(const LabelDecoratorBase& other) const {
    return getText() == other.getText();
}