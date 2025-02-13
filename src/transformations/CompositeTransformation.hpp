#pragma once
#include "TextTransformation.hpp"
#include <vector>
#include <memory>

class CompositeTransformation : public TextTransformation {
public:
    CompositeTransformation() = default;
    
    explicit CompositeTransformation(std::vector<std::unique_ptr<TextTransformation>> transformations)
        : transformations(std::move(transformations)) {}
    
    template<typename... Args>
    static std::unique_ptr<CompositeTransformation> create(Args... args) {
        auto composite = std::make_unique<CompositeTransformation>();
        (composite->add(std::move(args)), ...);
        return composite;
    }

    std::string transform(const std::string& text) const override {
        std::string transformed_text = text;
        for (const auto& transformation : transformations) {
            transformed_text = transformation->transform(transformed_text);
        }
        return transformed_text;
    }

    bool operator==(const TextTransformation& other) const override {
        const CompositeTransformation* other_composite = dynamic_cast<const CompositeTransformation*>(&other);
        if (!other_composite) {
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

    void add(std::unique_ptr<TextTransformation> transformation) {
        transformations.push_back(std::move(transformation));
    }

    void remove(const TextTransformation& transformation) {
        for (auto it = transformations.begin(); it != transformations.end(); ++it) {
            if (transformation == **it) {
                transformations.erase(it);
                return;
            }
        }
    }

    std::unique_ptr<TextTransformation> clone() const override {
        auto composite = std::make_unique<CompositeTransformation>();
        for (const auto& transformation : transformations) {
            composite->add(transformation->clone());
        }
        return composite;
    }

private:
    std::vector<std::unique_ptr<TextTransformation>> transformations;
};