#include "catch2/catch_all.hpp"
#include "decorators/RandomTransformationDecorator.hpp"
#include "labels/SimpleLabel.hpp"
#include "labels/RichLabel.hpp"
#include "decorators/TextTransformationDecorator.hpp"
#include "transformations/CapitalizeTransformation.hpp"
#include "transformations/CensorTransformation.hpp"
#include "transformations/LeftTrimTransformation.hpp"
#include "transformations/RightTrimTransformation.hpp"
#include "transformations/NormalizeSpaceTransformation.hpp"
#include "transformations/ReplaceTransformation.hpp"
#include "transformations/DecorateTransformation.hpp"

SCENARIO("No transformations are given") {
    GIVEN("A SimpleLabel, a RichLabel and a vector with only one transformation") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" crap! This is  very bad! ");
        std::shared_ptr<Label> rich_label = std::make_shared<RichLabel>(
            " you   bad boy! Don't crap   on the  carpet!  ",
            Color(0x00FF00),
            Font("Arial", 12)
        );

        std::vector<std::unique_ptr<TextTransformation>> transformations;
        WHEN("A RandomTransformationDecorator is applied") {
            THEN("An exception should be thrown") {
                REQUIRE_THROWS_AS(std::make_shared<RandomTransformationDecorator>(simple_label, transformations), std::invalid_argument);
                REQUIRE_THROWS_AS(std::make_shared<RandomTransformationDecorator>(rich_label, transformations), std::invalid_argument);
            }
        }
    }
}

SCENARIO("Only one transformation is given inside the vector") {
    GIVEN("A SimpleLabel, a RichLabel and a vector with only one transformation") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" crap! This is  very bad! ");
        std::shared_ptr<Label> rich_label = std::make_shared<RichLabel>(
            " you   bad boy! Don't crap   on the  carpet!  ",
            Color(0x00FF00),
            Font("Arial", 12)
        );

        std::vector<std::unique_ptr<TextTransformation>> transformations;
        transformations.push_back(std::make_unique<ReplaceTransformation>("bad", "abysmal"));
        WHEN("A RandomTransformationDecorator is applied with seed 1234") {
            simple_label = std::make_shared<RandomTransformationDecorator>(
                std::move(simple_label), transformations, 1234);
            rich_label = std::make_shared<RandomTransformationDecorator>(
                std::move(rich_label), transformations, 1234);

            THEN("The text should be transformed randomly") {
                REQUIRE(simple_label->getText() == " crap! This is  very abysmal! ");
                REQUIRE(rich_label->getText() == " you   abysmal boy! Don't crap   on the  carpet!  ");
            }
        }
        WHEN("A RandomTransformationDecorator is applied with seed 5678") {
            simple_label = std::make_shared<RandomTransformationDecorator>(
                std::move(simple_label), transformations, 5678);
            rich_label = std::make_shared<RandomTransformationDecorator>(
                std::move(rich_label), transformations, 5678);

            THEN("The text should be transformed the same way") {
                REQUIRE(simple_label->getText() == " crap! This is  very abysmal! ");
                REQUIRE(rich_label->getText() == " you   abysmal boy! Don't crap   on the  carpet!  ");
            }
        }
    }
}

SCENARIO("Applying random transformations on labels") {
    GIVEN("A SimpleLabel, a RichLabel and a vector of transformations") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" crap! This is  very bad! ");
        std::shared_ptr<Label> rich_label = std::make_shared<RichLabel>(
            " you   bad boy! Don't crap   on the  carpet!  ",
            Color(0x00FF00),
            Font("Arial", 12)
        );

        std::vector<std::unique_ptr<TextTransformation>> transformations;
        transformations.push_back(std::make_unique<CapitalizeTransformation>());
        transformations.push_back(std::make_unique<CensorTransformation>("crap"));
        transformations.push_back(std::make_unique<LeftTrimTransformation>());
        transformations.push_back(std::make_unique<RightTrimTransformation>());
        transformations.push_back(std::make_unique<NormalizeSpaceTransformation>());
        transformations.push_back(std::make_unique<ReplaceTransformation>("bad", "abysmal"));
        transformations.push_back(std::make_unique<DecorateTransformation>());

        WHEN("A RandomTransformationDecorator is applied with seed 1234, which seems to pick the TrimLeftTransformation") {
            simple_label = std::make_shared<RandomTransformationDecorator>(
                std::move(simple_label), transformations, 1234);
            rich_label = std::make_shared<RandomTransformationDecorator>(
                std::move(rich_label), transformations, 1234);

            THEN("The text should be transformed randomly") {
                REQUIRE(simple_label->getText() == "crap! This is  very bad! ");
                REQUIRE(rich_label->getText() == "you   bad boy! Don't crap   on the  carpet!  ");
            }
            WHEN("The decorator is applied with the same seed") {
                simple_label = std::make_shared<RandomTransformationDecorator>(
                    std::move(simple_label), transformations, 1234);
                rich_label = std::make_shared<RandomTransformationDecorator>(
                    std::move(rich_label), transformations, 1234);

                THEN("The text should be transformed the same way") {
                    REQUIRE(simple_label->getText() == "crap! This is  very bad! ");
                    REQUIRE(rich_label->getText() == "you   bad boy! Don't crap   on the  carpet!  ");
                }
            }
            WHEN("The decorator is applied with a different seed") {
                simple_label = std::make_shared<RandomTransformationDecorator>(
                    std::move(simple_label), transformations, 5678);
                rich_label = std::make_shared<RandomTransformationDecorator>(
                    std::move(rich_label), transformations, 5678);

                THEN("The text should (hopefully) be transformed differently, in this case it picks the TrimLeftTransformation") {
                    REQUIRE(simple_label->getText() == "crap! This is  very bad!");
                    REQUIRE(rich_label->getText() == "you   bad boy! Don't crap   on the  carpet!");
                }
            }
        }
    }
}