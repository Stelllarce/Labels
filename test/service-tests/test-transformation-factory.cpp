#include "catch2/catch_all.hpp"
#include "services/TransformationFactory.hpp"
#include "labels/SimpleLabel.hpp"
#include "decorators/TextTransformationDecorator.hpp"

SCENARIO("Creating single transformations using TransformationFactory") {
    GIVEN("Requests for different types of transformations") {
        WHEN("Creating a capitalize transformation") {
            auto trans = TransformationFactory::createTransformation("capitalize");
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            label = std::make_unique<TextTransformationDecorator>(
                std::move(label), 
                std::unique_ptr<TextTransformation>(trans->clone())
            );

            THEN("The transformation should work correctly") {
                REQUIRE(label->getText() == "Hello world");
            }
        }

        WHEN("Creating a censor transformation") {
            auto trans = TransformationFactory::createTransformation("censor:world");
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            label = std::make_unique<TextTransformationDecorator>(
                std::move(label), 
                std::unique_ptr<TextTransformation>(trans->clone())
            );

            THEN("The transformation should work correctly") {
                REQUIRE(label->getText() == "hello *****");
            }
        }

        WHEN("Creating a replace transformation") {
            auto trans = TransformationFactory::createTransformation("replace from:world to:everyone");
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            label = std::make_unique<TextTransformationDecorator>(
                std::move(label), 
                std::unique_ptr<TextTransformation>(trans->clone())
            );

            THEN("The transformation should work correctly") {
                REQUIRE(label->getText() == "hello everyone");
            }
        }

        WHEN("Creating trim transformations") {
            auto left_trim = TransformationFactory::createTransformation("left_trim");
            auto right_trim = TransformationFactory::createTransformation("right_trim");
            
            std::unique_ptr<Label> label1 = std::make_unique<SimpleLabel>("  hello  ");
            std::unique_ptr<Label> label2 = std::make_unique<SimpleLabel>("  hello  ");
            
            label1 = std::make_unique<TextTransformationDecorator>(
                std::move(label1), 
                std::unique_ptr<TextTransformation>(left_trim->clone())
            );
            label2 = std::make_unique<TextTransformationDecorator>(
                std::move(label2), 
                std::unique_ptr<TextTransformation>(right_trim->clone())
            );

            THEN("The transformations should work correctly") {
                REQUIRE(label1->getText() == "hello  ");
                REQUIRE(label2->getText() == "  hello");
            }
        }
    }
}

SCENARIO("Creating multiple transformations using TransformationFactory") {
    GIVEN("A command string with multiple transformations") {
        WHEN("Creating a set of valid transformations") {
            auto transformations = TransformationFactory::createTransformations(
                "capitalize censor:world normalize_space"
            );

            THEN("All transformations should be created") {
                REQUIRE(transformations.size() == 3);
                
                std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello  world");
                for (const auto& trans : transformations) {
                    label = std::make_unique<TextTransformationDecorator>(
                        std::move(label), 
                        std::unique_ptr<TextTransformation>(trans->clone())
                    );
                }
                REQUIRE(label->getText() == "Hello *****");
            }
        }

        WHEN("Creating transformations with some invalid commands") {
            auto transformations = TransformationFactory::createTransformations(
                "capitalize invalid_command normalize_space"
            );

            THEN("Only valid transformations should be created") {
                REQUIRE(transformations.size() == 2);
            }
        }
    }
}