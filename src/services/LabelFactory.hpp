#pragma once
#include "labels/CustomLabel.hpp"
#include "labels/SimpleLabel.hpp"
#include "labels/RichLabel.hpp"
#include <memory>
#include <string>

class LabelFactory {
public:
    static std::unique_ptr<Label> createLabel(
        const std::string& type,
        const std::string& text,
        const std::string& options = ""
    );

    // Helper method to parse options strings in format "key:value"
    static std::string getOption(const std::string& options, const std::string& key);
};