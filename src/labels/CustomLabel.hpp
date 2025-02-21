#pragma once
#include "SimpleLabel.hpp"
#include <memory>
#include <iostream>
#include "utils/HelpText.hpp"

/**
 * @class label class that makes use of the proxy pattern
 */
class CustomLabel : public Label {
public:
    CustomLabel(std::istream& is) : is(is) {}
    explicit CustomLabel(std::unique_ptr<HelpText> complication);
    std::string getText() const override;
    std::string getDetails() const override;
    std::string getHelpText() const override;
    void setHelpText(const std::string& help_txt) override;
protected:
    std::shared_ptr<SimpleLabel> getLabel() const;
    void promptChange() const;
private:
    mutable std::shared_ptr<SimpleLabel> label = nullptr;
    // increments after each call to getText()
    mutable size_t requests = 0;
    // when requests become or or equal to timeout, user is prompted to change label text
    static constexpr size_t TIMEOUT = 4;

    std::istream& is = std::cin;
#define UNIT_TESTING
#ifdef UNIT_TESTING
public:
    CustomLabel(std::istream& is, std::unique_ptr<HelpText> help_text) : is(is), Label(std::move(help_text)) {}
#endif // UNIT_TESTING
};