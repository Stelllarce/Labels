#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"

class TextTransformationDecorator : public LabelDecoratorBase {
public:
    explicit TextTransformationDecorator(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> transformation);
    std::string getText() const override;
private:
    std::unique_ptr<TextTransformation> transformation;
};