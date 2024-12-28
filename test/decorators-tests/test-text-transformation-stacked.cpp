#include "catch2/catch_all.hpp"
#include "decorators/TextTransformationDecorator.hpp"
#include "labels/SimpleLabel.hpp"
#include "labels/RichLabel.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/CensorTransformation.hpp"
#include "transformations/LeftTrimTransformation.hpp"
#include "transformations/RightTrimTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"

SCENARIO("Applying sequential transformations on labels using TransformationDecorator") {
    
    GIVEN("A SimpleLabel and a RichLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");
        std::shared_ptr<Label> rich_label = std::make_shared<RichLabel>(
            "   this is  another      label, that uses  a rich  font! ",
            Color(0x00FF00), 
            Font("Arial", 12)
        );

        WHEN("A LeftTrimTransformation is applied") {
            simple_label = std::make_shared<TextTransformationDecorator>(
                std::move(simple_label), std::make_unique<LeftTrimTransformation>());
            rich_label = std::make_shared<TextTransformationDecorator>(
                std::move(rich_label), std::make_unique<LeftTrimTransformation>());

            THEN("Leading spaces should be removed") {
                REQUIRE(simple_label->getText() == "this label     describes  a    design pattern!  ");
                REQUIRE(rich_label->getText() == "this is  another      label, that uses  a rich  font! ");
            }

            AND_WHEN("A CapitalizeTransformation is applied") {
                simple_label = std::make_shared<TextTransformationDecorator>(
                    std::move(simple_label), std::make_unique<CapitalizeTransformation>());
                rich_label = std::make_shared<TextTransformationDecorator>(
                    std::move(rich_label), std::make_unique<CapitalizeTransformation>());

                THEN("The text should start with an uppercase letter") {
                    REQUIRE(simple_label->getText() == "This label     describes  a    design pattern!  ");
                    REQUIRE(rich_label->getText() == "This is  another      label, that uses  a rich  font! ");
                }

                AND_WHEN("A NormalizeSpaceTransformation is applied") {
                    simple_label = std::make_shared<TextTransformationDecorator>(
                        std::move(simple_label), std::make_unique<NormalizeSpaceTransformation>());
                    rich_label = std::make_shared<TextTransformationDecorator>(
                        std::move(rich_label), std::make_unique<NormalizeSpaceTransformation>());

                    THEN("Consecutive spaces should be reduced to a single space") {
                        REQUIRE(simple_label->getText() == "This label describes a design pattern! ");
                        REQUIRE(rich_label->getText() == "This is another label, that uses a rich font! ");
                    }

                    AND_WHEN("A RightTrimTransformation is applied") {
                        simple_label = std::make_shared<TextTransformationDecorator>(
                            std::move(simple_label), std::make_unique<RightTrimTransformation>());
                        rich_label = std::make_shared<TextTransformationDecorator>(
                            std::move(rich_label), std::make_unique<RightTrimTransformation>());

                        THEN("Trailing spaces should be removed") {
                            REQUIRE(simple_label->getText() == "This label describes a design pattern!");
                            REQUIRE(rich_label->getText() == "This is another label, that uses a rich font!");
                        }
                        AND_WHEN("A DecorateTransformation is applied") {
                            simple_label = std::make_shared<TextTransformationDecorator>(
                                std::move(simple_label), std::make_unique<DecorateTransformation>());
                            rich_label = std::make_shared<TextTransformationDecorator>(
                                std::move(rich_label), std::make_unique<DecorateTransformation>());

                            THEN("The text should be enclosed in square brackets") {
                                REQUIRE(simple_label->getText() == "-={ This label describes a design pattern! }=-");
                                REQUIRE(rich_label->getText() == "-={ This is another label, that uses a rich font! }=-");
                            }
                        }
                    }
                }
            }
        }
    }
}
