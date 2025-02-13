#include "CensorTransformationFactory.hpp"

/**
 * @brief creates a new CensoredLetter if it doesn't exist in the pool
 * @param letter the letter to censor
 * @return shared pointer to the censored letter
 */
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

/**
 * @brief creates a new CensorTransformation for a given word
 * @param to_censor the word to censor
 * @return shared pointer to the new CensorTransformation
 */
std::shared_ptr<CensorTransformation> CensorTransformationFactory::createCensorTransformation(
    const std::string& to_censor) {
    
    // Create new CensorTransformation
    return std::make_shared<CensorTransformation>(to_censor);
}