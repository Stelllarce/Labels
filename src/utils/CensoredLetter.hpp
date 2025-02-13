#pragma once

class CensoredLetter {
public:
    explicit CensoredLetter(char original);
    
    char getOriginal() const;
    char getCensored() const;

private:
    char original_letter;
};