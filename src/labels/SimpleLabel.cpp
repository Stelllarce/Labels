#include "SimpleLabel.hpp"

SimpleLabel::SimpleLabel(const std::string& value) : value(value) {}

/**
 * @return the text of the label
 */
std::string SimpleLabel::getText() const {
    return value;
}

/**
 * @return empty string
 */
std::string SimpleLabel::getDetails() const {
    return "";
}