#include "TransformationFactory.hpp"
#include <sstream>

// Helper function to extract a parameter from a command string
// Hidden in an unnamed namespace to avoid polluting the global namespace
namespace {
    std::string getParameter(const std::string& command, const std::string& param) {
        size_t pos = command.find(param + ":");
        if (pos == std::string::npos) return "";
        
        size_t start = pos + param.length() + 1;
        size_t end = command.find(" ", start);
        if (end == std::string::npos) end = command.length();
        
        return command.substr(start, end - start);
    }
}

/**
 * @brief Creates a single transformation from a command string
 * @param command the command string
 * @return shared pointer to the created transformation 
 * or nullptr if the command is invalid
 */
std::shared_ptr<TextTransformation> TransformationFactory::createTransformation(
    const std::string& command) {
    
    if (command == "capitalize") {
        return std::make_shared<CapitalizeTransformation>();
    }
    
    if (command == "decorate") {
        return std::make_shared<DecorateTransformation>();
    }
    
    if (command == "left_trim") {
        return std::make_shared<LeftTrimTransformation>();
    }
    
    if (command == "right_trim") {
        return std::make_shared<RightTrimTransformation>();
    }
    
    if (command == "normalize_space") {
        return std::make_shared<NormalizeSpaceTransformation>();
    }
    
    if (command.find("censor:") == 0) {
        std::string word = command.substr(7);
        return std::make_shared<CensorTransformation>(word);
    }
    
    if (command.find("replace") == 0) {
        std::string from = getParameter(command, "from");
        std::string to = getParameter(command, "to");
        if (!from.empty() && !to.empty()) {
            return std::make_shared<ReplaceTransformation>(from, to);
        }
    }
    
    return nullptr;
}

std::vector<std::shared_ptr<TextTransformation>> TransformationFactory::createTransformations(
    const std::string& commands) {
    
    std::vector<std::shared_ptr<TextTransformation>> transformations;
    std::istringstream iss(commands);
    std::string command;
    
    while (std::getline(iss, command, ' ')) {
        if (command.empty()) continue;
        
        auto transformation = createTransformation(command);
        if (transformation) {
            transformations.push_back(std::move(transformation));
        }
    }
    
    return transformations;
}