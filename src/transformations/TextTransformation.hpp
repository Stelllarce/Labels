#pragma once
#include <string>
#include <stdexcept>
#include <memory>

/**
 * @interface for all text transformations
 */
class TextTransformation {
public:
    virtual std::string transform(const std::string& text) const = 0;
    virtual bool operator==(const TextTransformation& other) const = 0;

    virtual void add(std::unique_ptr<TextTransformation> transformation) {
        return;
    }
    virtual void remove(std::unique_ptr<TextTransformation> transformation) {
        return;
    }

    virtual std::unique_ptr<TextTransformation> clone() const = 0;
    virtual ~TextTransformation() = default;
};