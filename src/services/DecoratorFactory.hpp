#pragma once
#include "decorators/TextTransformationDecorator.hpp"
#include "decorators/CyclingTransformationsDecorator.hpp"
#include "decorators/RandomTransformationDecorator.hpp"
#include "TransformationFactory.hpp"
#include <memory>
#include <string>

class DecoratorFactory {
public:
    // type: "simple", "cycling", or "random"
    // For simple: transformCommand is a single transformation command
    // For cycling/random: transformCommand is space-separated transformation commands
    static std::unique_ptr<LabelDecoratorBase> createDecorator(
        const std::string& type,
        std::unique_ptr<Label> label,
        const std::string& transformCommand
    );
};