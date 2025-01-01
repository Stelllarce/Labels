#pragma once
#include "TextTransformation.hpp"
#include <vector>
#include <memory>
#include <initializer_list>

class CompositeTransformation : public TextTransformation {
public:
    CompositeTransformation(std::initializer_list<std::shared_ptr<TextTransformation>> transformations);
    std::string transform(const std::string& text) const override;
    bool operator==(const TextTransformation& other) const override;

    void add(const std::shared_ptr<TextTransformation>& transformation) override;
    void remove(const std::shared_ptr<TextTransformation>& transformation) override;
private:
    std::vector<std::shared_ptr<TextTransformation>> transformations;
};