#include "CyclingTransformationsDecorator.hpp"

/**
 * @param label the label to decorate
 * @param transformations the transformations to apply
 */
CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::unique_ptr<Label> label, const std::vector<std::unique_ptr<TextTransformation>>& transformations)
    : LabelDecoratorBase(std::move(label)) {
        for (const auto& transformation : transformations) 
            this->transformations.push_back(transformation->clone());
    }

/**
 * @brief decorates the text with a transformation chosen from the vector
 * @return a transformation from the list in order, starting from 0, then after reaching the last
 * transformation, it starts from the beginning
 */
std::string CyclingTransformationsDecorator::getText() const {
    if (!getLabel()) return "";
    return transformations[index++ % transformations.size()]->transform(getLabel()->getText());
}

std::string CyclingTransformationsDecorator::getDetails() const{
    return LabelDecoratorBase::getLabel()->getDetails();
}

bool CyclingTransformationsDecorator::operator==(const LabelDecoratorBase& other) const {
    if (const auto derived = dynamic_cast<const CyclingTransformationsDecorator*>(&other)) {
        for (size_t i = 0; i < transformations.size(); i++) {
            if (!(*(transformations[i]) == *(derived->transformations[i]))) return false;
        }
    }
    return true;
}