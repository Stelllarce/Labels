#include "TextTransformationDecorator.hpp"

TextTransformationDecorator::TextTransformationDecorator(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> transformation)
    : LabelDecoratorBase(label), transformation(std::move(transformation)) {}

std::string TextTransformationDecorator::getText() const {
    return transformation->transform(LabelDecoratorBase::getText());
}

std::string TextTransformationDecorator::getDetails() const {
    return LabelDecoratorBase::getDetails();
}