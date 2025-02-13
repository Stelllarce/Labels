#include "LabelFactory.hpp"
#include <sstream>

std::string LabelFactory::getOption(const std::string& options, const std::string& key) {
    if (options.empty() || key.empty()) {
        return "";
    }

    size_t pos = options.find(key + ":");
    if (pos == std::string::npos) return "";
    
    size_t start = pos + key.length() + 1;
    if (start >= options.length()) return "";

    size_t end = options.find(" ", start);
    if (end == std::string::npos) end = options.length();
    
    return options.substr(start, end - start);
}

std::unique_ptr<Label> LabelFactory::createLabel(
    const std::string& type,
    const std::string& text,
    const std::string& options) {
    
    std::unique_ptr<Label> label;
    std::string helpText = getOption(options, "helptext");
    
    if (type == "simple") {
        if (helpText.empty()) {
            label = std::make_unique<SimpleLabel>(text, std::make_unique<HelpText>(""));
        } else {
            label = std::make_unique<SimpleLabel>(text, std::make_unique<HelpText>(helpText));
        }
        return label;
    }
    
    if (type == "rich") {
        std::string color = getOption(options, "color");
        std::string font = getOption(options, "font");
        std::string fontSize = getOption(options, "font_size");
        
        if (color.empty() || font.empty() || fontSize.empty()) {
            return nullptr;
        }

        if (helpText.empty()) {
            helpText = "";
        }

        return std::make_unique<RichLabel>(
            text,
            color,
            font + ":" + fontSize,
            std::make_unique<HelpText>(helpText)
        );
    }
    
    if (type == "custom") {
        std::stringstream* ss = new std::stringstream(text);
        if (helpText.empty()) {
            label = std::unique_ptr<CustomLabel>(new CustomLabel(*ss, std::make_unique<HelpText>("")));
        } else {
            label = std::unique_ptr<CustomLabel>(new CustomLabel(*ss, std::make_unique<HelpText>(helpText)));
        }
        return label;
    }
    
    return nullptr;
}