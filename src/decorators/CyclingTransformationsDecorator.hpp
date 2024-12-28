#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"
#include <vector>

class CyclingTransformationsDecorator : public LabelDecoratorBase {
public:
    CyclingTransformationsDecorator(std::shared_ptr<Label> label, std::vector<std::shared_ptr<TextTransformation>> transformations);

    std::string getText() const override;
    std::string getDetails() const override;
private:
    std::vector<std::shared_ptr<TextTransformation>> transformations;
    mutable size_t index = 0;
};