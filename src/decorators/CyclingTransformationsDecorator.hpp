#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"
#include <vector>

/**
 * @class decorator that applies a series of transformations to the text in a cycling manner
 */
class CyclingTransformationsDecorator : public LabelDecoratorBase {
public:
    CyclingTransformationsDecorator(std::shared_ptr<Label> label, std::vector<std::shared_ptr<TextTransformation>> transformations);

    /**
     * @brief decorates the text with a transformation chosen from the vector
     */
    std::string getText() const override;
    std::string getDetails() const override;
private:
    std::vector<std::shared_ptr<TextTransformation>> transformations;
    // index of the current transformation to be applied
    mutable size_t index = 0;
};