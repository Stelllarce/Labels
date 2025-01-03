#pragma once
#include <string>
#include <memory>

class HelpLabel;

/**
 * @interface for all labels
 */
class Label {
public:
    /**
     * @brief invoke concrete operation about the label
     * (usually print it)
     */
    virtual std::string getText() const = 0;

    /**
     * @brief use to print any additional information about a label
     * added so labels can be distinguished from each other
     */
    virtual std::string getDetails() const = 0;
    virtual ~Label() = default;
protected:
    Label() = default;
    Label(std::unique_ptr<HelpLabel> help_label) : help_label(std::move(help_label)) {}
    HelpLabel* getHelpLabel() const { return help_label.get(); }
private:
    std::unique_ptr<HelpLabel> help_label;
};