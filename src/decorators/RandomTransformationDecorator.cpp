#include "RandomTransformationDecorator.hpp"

RandomTransformationDecorator::RandomTransformationDecorator(
    std::shared_ptr<Label> label, 
    const std::vector<std::unique_ptr<TextTransformation>>& transformations,
    long seed)
    : LabelDecoratorBase(std::move(label)), 
    transformations(transformations),
    seed(seed) {
        if (transformations.empty()) throw std::invalid_argument("No transformations given");
    }

std::string RandomTransformationDecorator::getText() const {
    std::srand(seed);
    size_t random_index = std::rand() % transformations.size();
    return transformations[random_index]->transform(LabelDecoratorBase::label->getText());
}

std::string RandomTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::label->getDetails();
}