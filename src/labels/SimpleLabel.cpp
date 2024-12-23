#include "SimpleLabel.hpp"

SimpleLabel::SimpleLabel(const std::string& value) : value(value) {}

std::string SimpleLabel::getText() const {
    return value;
}