#include "CompositeTransformation.hpp"

CompositeTransformation::CompositeTransformation(std::initializer_list<std::shared_ptr<TextTransformation>> transformations) : transformations(transformations) {}

std::string CompositeTransformation::transform(const std::string& text) const {
    std::string transformed_text = text;
    for (const auto& transformation : transformations) {
        transformed_text = transformation->transform(transformed_text);
    }
    return transformed_text;
}

bool CompositeTransformation::operator==(const TextTransformation& other) const {
    const CompositeTransformation* other_composite = dynamic_cast<const CompositeTransformation*>(&other);
    if (!other_composite ) {
        return false;
    }
    if (transformations.size() != other_composite->transformations.size()) {
        return false;
    }
    for (size_t i = 0; i < transformations.size(); ++i) {
        if (!(*transformations[i] == *other_composite->transformations[i])) {
            return false;
        }
    }
    return true;
}

void CompositeTransformation::add(const std::shared_ptr<TextTransformation>& transformation) {
    transformations.push_back(transformation);
}

void CompositeTransformation::remove(const std::shared_ptr<TextTransformation>& transformation) {
    for (auto it = transformations.begin(); it != transformations.end(); ++it) {
        if (*transformation == **it) {
            transformations.erase(it);
            return;
        }
    }
}

std::unique_ptr<TextTransformation> CompositeTransformation::clone() const {
    std::vector<std::shared_ptr<TextTransformation>> cloned_transformations;
    for (const auto& transformation : transformations) {
        cloned_transformations.push_back(transformation->clone());
    }
    return std::make_unique<CompositeTransformation>(cloned_transformations);
}