#pragma once

/**
 * @class class that represents a letter that has been censored
 */
class CensoredLetter {
public:
    explicit CensoredLetter(char original);
    
    char getOriginal() const;
    char getCensored() const;

private:
    char original_letter;
};