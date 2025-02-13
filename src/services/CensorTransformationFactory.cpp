#include "CensorTransformationFactory.hpp"


std::shared_ptr<CensoredLetter> CensorTransformationFactory::getCensoredLetter(char letter) {
    auto it = letter_pool.find(letter);
    if (it != letter_pool.end()) {
        return it->second;
    }
    
    // Create new censored letter if not found
    auto new_letter = std::make_shared<CensoredLetter>(letter);
    letter_pool[letter] = new_letter;
    return new_letter;
}

std::shared_ptr<CensorTransformation> CensorTransformationFactory::createCensorTransformation(
    const std::string& to_censor) {
    
    // Create new CensorTransformation
    return std::make_shared<CensorTransformation>(to_censor);
}