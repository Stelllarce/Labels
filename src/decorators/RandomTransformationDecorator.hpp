#pragma once
#include "LabelDecoratorBase.hpp"
#include "transformations/TextTransformation.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

class RandomTransformationDecorator : public LabelDecoratorBase {
public:
    RandomTransformationDecorator(std::shared_ptr<Label> label, const std::vector<std::unique_ptr<TextTransformation>>&  transformations, long seed = time(NULL));
    std::string getText() const override;
    std::string getDetails() const override;
private:
    const std::vector<std::unique_ptr<TextTransformation>>& transformations;
    long seed;
};