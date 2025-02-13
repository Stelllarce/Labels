#pragma once
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/CensorTransformation.hpp"
#include "transformations/CompositeTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"
#include "transformations/LeftTrimTransformation.hpp"
#include "transformations/RightTrimTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include <memory>
#include <string>
#include <vector>

class TransformationFactory {
public:
    // Create single transformation from string command
    // Examples: 
    // "capitalize"
    // "censor:bad"
    // "replace from:bad to:good"
    static std::shared_ptr<TextTransformation> createTransformation(const std::string& command);

    // Create multiple transformations from space-separated commands
    static std::vector<std::shared_ptr<TextTransformation>> createTransformations(const std::string& commands);
};