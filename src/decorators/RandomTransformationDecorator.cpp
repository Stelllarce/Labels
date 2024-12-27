#include "RandomTransformationDecorator.hpp"

RandomTransformationDecorator::RandomTransformationDecorator(
    std::shared_ptr<Label> label, 
    const std::vector<std::unique_ptr<TextTransformation>>& transformations,
    long seed)
    : LabelDecoratorBase(std::move(label)), 
    transformations(transformations),
    seed(seed) {}

std::string RandomTransformationDecorator::getText() const {
    if (transformations.empty()) return LabelDecoratorBase::label->getText();
    std::srand(seed);
    size_t random_index = std::rand() % transformations.size();
    return transformations[random_index]->transform(LabelDecoratorBase::label->getText());
}

std::string RandomTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::label->getDetails();
}