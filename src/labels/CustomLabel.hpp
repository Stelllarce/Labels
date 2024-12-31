#pragma once
#include "SimpleLabel.hpp"
#include <memory>
#include <iostream>

/**
 * a label class that makes use of the proxy pattern
 */
class CustomLabel : public Label {
public:
    CustomLabel() = default;
    std::string getText() const override;
    std::string getDetails() const override;
protected:
    std::shared_ptr<SimpleLabel> getLabel() const;
    void promptChange() const;
private:
    mutable std::shared_ptr<SimpleLabel> label = nullptr;
    // increments after each call of getText()
    mutable size_t requests = 0;
    // when requests become or or equal to timeout, user is prompted to change label text
    static constexpr size_t TIMEOUT = 4;

#define UNIT_TESTING
#ifdef UNIT_TESTING
    std::istream& is = std::cin;
public:
    CustomLabel(std::istream& is) : is(is) {}
#endif // UNIT_TESTING
};