#pragma once
#include "utils/Complication.hpp"
#include <string>
#include <memory>

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
    virtual ~Label() = default;
protected:
    Label(std::unique_ptr<Complication> complication) : complication(std::move(complication)) {};
    Label() {};
    Complication* getComplication() const { return complication.get(); }; 
public:
    std::unique_ptr<Complication> complication;
};