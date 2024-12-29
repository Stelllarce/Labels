#include "TextTransformationDecorator.hpp"

/**
 * @param label to decorate
 * @param transformations to be applied
 */
TextTransformationDecorator::TextTransformationDecorator(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> transformation)
    : LabelDecoratorBase(label), transformation(std::move(transformation)) {}

/**
 * @returns the string with an applied tranformation
 */
std::string TextTransformationDecorator::getText() const {
    if (!label || !transformation) return "";
    return transformation->transform(LabelDecoratorBase::getText());
}

std::string TextTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::getDetails();
}