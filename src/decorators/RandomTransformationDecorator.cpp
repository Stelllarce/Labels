#include "RandomTransformationDecorator.hpp"

/**
 * @param label to decorate
 * @param transformations vector of transformations
 * @param seed for testing, defaults to current time if not given
 */
RandomTransformationDecorator::RandomTransformationDecorator(
    std::shared_ptr<Label> label, 
    const std::vector<std::shared_ptr<TextTransformation>>& transformations,
    long seed)
    : LabelDecoratorBase(std::move(label)), 
    transformations(transformations),
    seed(seed) {}

/**
 * @brief generates a random number to pick a transformation from
 * an index. if no transformations were given, do nothing
 * @return the decorated string
 */
std::string RandomTransformationDecorator::getText() const {
    if (!label) return "";
    if (transformations.empty()) return LabelDecoratorBase::label->getText();
    std::srand(seed);
    size_t random_index = std::rand() % transformations.size();
    return transformations[random_index]->transform(LabelDecoratorBase::label->getText());
}

std::string RandomTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::label->getDetails();
}