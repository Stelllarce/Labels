#include "DecoratorFactory.hpp"
#include <iostream>

// Helper function to convert shared_ptr to unique_ptr
// Hidden in a namespace to avoid polluting the global namespace
namespace {
    std::vector<std::unique_ptr<TextTransformation>> convertToUnique(
        const std::vector<std::shared_ptr<TextTransformation>>& shared_transformations) {
        
        std::vector<std::unique_ptr<TextTransformation>> unique_transformations;
        
        // Check if input is empty
        if (shared_transformations.empty()) {
            return unique_transformations;
        }

        unique_transformations.reserve(shared_transformations.size());
        
        for (const auto& trans : shared_transformations) {
            if (trans != nullptr) {
                unique_transformations.push_back(std::unique_ptr<TextTransformation>(trans->clone()));
            }
        }
        
        return unique_transformations;
    }
}

/**
 * @brief Creates a label decorator based on the type and transformation command
 * @param type the type of decorator to create
 * @param label the label to decorate
 * @param transformCommand the transformation command to apply
 * @return a unique pointer to the created decorator
 */
std::unique_ptr<LabelDecoratorBase> DecoratorFactory::createDecorator(
    const std::string& type,
    std::unique_ptr<Label> label,
    const std::string& transformCommand) {
    
    // Guard against empty command
    if (transformCommand.empty()) {
        return nullptr;
    }

    if (type == "simple") {
        auto transformation = TransformationFactory::createTransformation(transformCommand);
        if (transformation) {
            return std::make_unique<TextTransformationDecorator>(
                std::move(label),
                std::unique_ptr<TextTransformation>(transformation->clone())
            );
        }
        return nullptr;
    }
    
    if (type == "cycling" || type == "random") {
        auto shared_transformations = TransformationFactory::createTransformations(transformCommand);
        
        // Guard against empty transformations
        if (shared_transformations.empty()) {
            return nullptr;
        }

        auto unique_transformations = convertToUnique(shared_transformations);
        
        // Guard against failed conversion
        if (unique_transformations.empty()) {
            return nullptr;
        }
        
        if (type == "cycling") {
            return std::make_unique<CyclingTransformationsDecorator>(
                std::move(label),
                std::move(unique_transformations)
            );
        } else {  // random
            return std::make_unique<RandomTransformationDecorator>(
                std::move(label),
                std::move(unique_transformations)
            );
        }
    }
    
    return nullptr;
}