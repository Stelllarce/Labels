#include "CyclingTransformationsDecorator.hpp"

CyclingTransformationsDecorator::CyclingTransformationsDecorator(std::shared_ptr<Label> label, std::vector<std::shared_ptr<TextTransformation>> transformations)
    : LabelDecoratorBase(std::move(label)), transformations(transformations) {}

std::string CyclingTransformationsDecorator::getText() const {
    return transformations[index++ % transformations.size()]->transform(LabelDecoratorBase::label->getText());
}

std::string CyclingTransformationsDecorator::getDetails() const{
    return LabelDecoratorBase::label->getDetails();
}