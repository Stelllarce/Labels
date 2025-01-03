#pragma once
#include "transformations/CensorTransformation.hpp"
#include <unordered_map>
#include <memory>
#include <initializer_list>

class CensorTransformationFactory {
public:
    CensorTransformationFactory(std::initializer_list<std::shared_ptr<CensorTransformation>> ctf_list);
    std::shared_ptr<CensorTransformation> createCensorTransformation(const std::string& to_censor);
private:
    std::unordered_map<std::string, std::shared_ptr<CensorTransformation>> pool;
};