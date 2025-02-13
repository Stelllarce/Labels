#pragma once
#include "transformations/CensorTransformation.hpp"
#include "utils/CensoredLetter.hpp"
#include <unordered_map>
#include <memory>
#include <string>

class CensorTransformationFactory {
public:
    CensorTransformationFactory() = default;
    
    // Creates a CensorTransformation for a given word, using flyweight letters internally
    std::shared_ptr<CensorTransformation> createCensorTransformation(const std::string& to_censor);

private:
    // Pool of flyweight censored letters
    std::unordered_map<char, std::shared_ptr<CensoredLetter>> letter_pool;
    
    // Get or create a censored letter flyweight
    std::shared_ptr<CensoredLetter> getCensoredLetter(char letter);
};