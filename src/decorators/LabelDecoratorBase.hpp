#pragma once
#include "labels/Label.hpp"
#include <memory>
/**
 * @class abstract decorator class that defines the interface for all concrete decorators
 */
class LabelDecoratorBase : public Label {
public:
    explicit LabelDecoratorBase(std::unique_ptr<Label> label);

    std::string getText() const override;
    std::string getDetails() const override;

    static std::unique_ptr<Label> removeDecoratorFrom(std::unique_ptr<Label> l, std::unique_ptr<LabelDecoratorBase> to_rm);

    virtual bool operator==(const LabelDecoratorBase& rhs) const;

    virtual ~LabelDecoratorBase() = default;
private:
    // contains original label to decorate later
    std::unique_ptr<Label> label;
protected:
    Label* getLabel() const { return label.get(); }
};