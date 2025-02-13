#include "RandomTransformationDecorator.hpp"

/**
 * @param label to decorate
 * @param transformations vector of transformations
 * @param seed for testing, defaults to current time if not given
 */
RandomTransformationDecorator::RandomTransformationDecorator(
    std::unique_ptr<Label> label, 
    const std::vector<std::unique_ptr<TextTransformation>>& transformations,
    long seed)
    : LabelDecoratorBase(std::move(label)), 
    seed(seed) {
        for (const auto& transformation : transformations) 
            this->transformations.push_back(transformation->clone());
    }

/**
 * @brief generates a random number to pick a transformation from
 * an index. if no transformations were given, do nothing
 * @return the decorated string
 */
std::string RandomTransformationDecorator::getText() const {
    if (!getLabel()) return "";
    if (transformations.empty()) return LabelDecoratorBase::getLabel()->getText();
    std::srand(seed);
    size_t random_index = std::rand() % transformations.size();
    return transformations[random_index]->transform(LabelDecoratorBase::getLabel()->getText());
}

std::string RandomTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::getLabel()->getDetails();
}

bool RandomTransformationDecorator::operator==(const LabelDecoratorBase& other) const {
    if (const RandomTransformationDecorator* derived = dynamic_cast<const RandomTransformationDecorator*>(&other)) {
        for (size_t i = 0; i < transformations.size(); i++) {
            if (!(*(transformations[i]) == *(derived->transformations[i]))) return false;
        }
    }
    return true;
}