#pragma once
#include "labels/Label.hpp"
#include <memory>
/**
 * @class abstract decorator class that defines the interface for all concrete decorators
 */
class LabelDecoratorBase : public Label {
public:
    explicit LabelDecoratorBase(const std::shared_ptr<Label>& label);

    std::string getText() const override;
    std::string getDetails() const override;

    static std::shared_ptr<Label> removeDecoratorFrom(std::shared_ptr<Label>& l, std::shared_ptr<LabelDecoratorBase>&& to_rm);

    virtual bool operator==(const LabelDecoratorBase& other) const;

    virtual ~LabelDecoratorBase() = default;
protected:
    // contains original label to decorate later
    std::shared_ptr<Label> label;
};