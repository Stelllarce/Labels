#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"

/**
 * @class decorator that contains and applies a single transformation at a time
 * also makes use of the strategy pattern
 */
class TextTransformationDecorator : public LabelDecoratorBase {
public:
    explicit TextTransformationDecorator(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> transformation);
    std::string getText() const override;
    std::string getDetails() const override;
private:
    std::unique_ptr<TextTransformation> transformation;
};