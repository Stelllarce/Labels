#include "CensoredLetter.hpp"

CensoredLetter::CensoredLetter(char original) : original_letter(original) {}

char CensoredLetter::getOriginal() const { 
    return original_letter; 
}

char CensoredLetter::getCensored() const { 
    return '*'; 
}