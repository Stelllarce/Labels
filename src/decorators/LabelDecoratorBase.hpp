#pragma once
#include "labels/Label.hpp"
#include <memory>

class LabelDecoratorBase : public Label {
public:
    LabelDecoratorBase(std::shared_ptr<Label> label);
    std::string getText() const override;
protected:
    std::shared_ptr<Label> label;
};