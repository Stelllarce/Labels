#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @class decorator that applies a random transformation
 * from a vector each time its invoked
 */
class RandomTransformationDecorator : public LabelDecoratorBase {
public:
    explicit RandomTransformationDecorator(std::shared_ptr<Label> label, const std::vector<std::shared_ptr<TextTransformation>>&  transformations, long seed = time(NULL));
    std::string getText() const override;
    std::string getDetails() const override;
    bool operator==(const LabelDecoratorBase& other) const override;
private:
    std::vector<std::shared_ptr<TextTransformation>> transformations;
    // contains a seed field for testing
    long seed;
};