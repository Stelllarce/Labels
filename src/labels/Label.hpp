#pragma once
#include "utils/Complication.hpp"
#include <string>
#include <memory>
#include <stdexcept>

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
    virtual std::string getHelpText() const { return ""; };
    virtual void setHelpText(const std::string& help_text) {};
    virtual ~Label() = default;
protected:
    Label() = default;
    Label(std::unique_ptr<Complication> complication) : complication(std::move(complication)) {};
    Complication* getComplication() const { return complication.get(); }; 
    std::unique_ptr<Complication> complication;
};