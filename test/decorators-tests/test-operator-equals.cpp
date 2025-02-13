#include "catch2/catch_all.hpp"
#include "decorators/TextTransformationDecorator.hpp"
#include "decorators/RandomTransformationDecorator.hpp"
#include "decorators/CyclingTransformationsDecorator.hpp"
#include "labels/SimpleLabel.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/CensorTransformation.hpp"
#include "transformations/LeftTrimTransformation.hpp"
#include "transformations/RightTrimTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"

TEST_CASE("Left transformation, both identical", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> left_trim = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("  hello  "), std::make_unique<LeftTrimTransformation>());
    std::unique_ptr<LabelDecoratorBase> left_trim2 = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("  hello  "), std::make_unique<LeftTrimTransformation>());
    
    REQUIRE(*left_trim == *left_trim2);
}

TEST_CASE("Censor transformation, both identical", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> censor = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<CensorTransformation>("hello"));
    std::unique_ptr<LabelDecoratorBase> censor2 = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<CensorTransformation>("hello"));
    
    REQUIRE(*censor == *censor2);
}

TEST_CASE("Censor transformation, different censor strings", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> censor = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<CensorTransformation>("hello"));
    std::unique_ptr<LabelDecoratorBase> censor2 = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<CensorTransformation>("world"));
    
    REQUIRE_FALSE(*censor == *censor2);
}

TEST_CASE("Replace transformation, both identical", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> replace = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<ReplaceTransformation>("hello", "world"));
    std::unique_ptr<LabelDecoratorBase> replace2 = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<ReplaceTransformation>("hello", "world"));
    
    REQUIRE(*replace == *replace2);
}

TEST_CASE("Replace transformation, different parameters", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> replace = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<ReplaceTransformation>("hello", "world"));
    std::unique_ptr<LabelDecoratorBase> replace2 = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<ReplaceTransformation>("world", "hello"));
    
    REQUIRE_FALSE(*replace == *replace2);
}

TEST_CASE("Compare diffrent transformations", "[TextTransformationDecorator]") {
    std::unique_ptr<LabelDecoratorBase> left_trim = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("  hello  "), std::make_unique<LeftTrimTransformation>());
    std::unique_ptr<LabelDecoratorBase> censor = std::make_unique<TextTransformationDecorator>(
        std::make_unique<SimpleLabel>("hello"), std::make_unique<CensorTransformation>("hello"));
    
    REQUIRE_FALSE(*left_trim == *censor);
}