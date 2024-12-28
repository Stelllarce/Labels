#pragma once
#include "labels/Label.hpp"
#include <memory>
/**
 * @class abstract decorator class that defines the interface for all concrete decorators
 */
class LabelDecoratorBase : public Label {
public:
    LabelDecoratorBase(std::shared_ptr<Label> label);

    std::string getText() const override;
    std::string getDetails() const override;
protected:
    // contains original label to decorate later
    std::shared_ptr<Label> label;
};