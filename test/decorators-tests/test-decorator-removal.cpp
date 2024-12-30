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
#include "decorators/RandomTransformationDecorator.hpp"
#include "decorators/CyclingTransformationsDecorator.hpp"

SCENARIO("Removing a decorator when none has been applied") {
    GIVEN("A SimpleLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");

        THEN("The text should be unmodified") {
            REQUIRE(simple_label != nullptr);
            REQUIRE(simple_label->getText() == " this label     describes  a    design pattern!  ");
        }

        WHEN("A LeftTrimTransformation is removed") {
            simple_label = LabelDecoratorBase::removeDecoratorFrom(simple_label, std::make_shared<TextTransformationDecorator>(
                nullptr, std::make_unique<LeftTrimTransformation>()));

            THEN("The text should be unmodified") {
                REQUIRE(simple_label != nullptr);
                REQUIRE(simple_label->getText() == " this label     describes  a    design pattern!  ");
            }
        }
    }
}

SCENARIO("Removing a single applied decorator") {
    GIVEN("A SimpleLabel with a LeftTrimTransformation applied") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");

        simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<LeftTrimTransformation>());
        
        THEN("Leading spaces should be removed") {
            REQUIRE(simple_label != nullptr);
            REQUIRE(simple_label->getText() == "this label     describes  a    design pattern!  ");
        }

        WHEN("The LeftTrimTransformation is removed") {
            simple_label = LabelDecoratorBase::removeDecoratorFrom(
                simple_label,
                std::make_shared<TextTransformationDecorator>(
                    nullptr, std::make_unique<LeftTrimTransformation>()));

            THEN("The text should be restored to its original state") {
                REQUIRE(simple_label != nullptr);
                REQUIRE(simple_label->getText() == " this label     describes  a    design pattern!  ");
            }
        }
    }   
}

SCENARIO("Removing a decorator that is in the middle of a long chain of diffrent decorators") {
    GIVEN("A SimpleLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");
        AND_GIVEN("Five diffrent transformations stacked on top of it") {
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<LeftTrimTransformation>());
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<CapitalizeTransformation>());
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<NormalizeSpaceTransformation>());
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<RightTrimTransformation>());
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<ReplaceTransformation>("design", "factory"));

            THEN("The text should be transformed correctly") {
                REQUIRE(simple_label != nullptr);
                REQUIRE(simple_label->getText() == "This label describes a factory pattern!");
            }

            WHEN("The NormalizeSpaceTransformation is removed") {
                simple_label = LabelDecoratorBase::removeDecoratorFrom(
                    simple_label,
                    std::make_shared<TextTransformationDecorator>(
                        nullptr, std::make_unique<NormalizeSpaceTransformation>()));

                THEN("The text should be restored to its previous state") {
                    REQUIRE(simple_label != nullptr);
                    REQUIRE(simple_label->getText() == "This label     describes  a    factory pattern!");
                }
            }
        }
    }
}

SCENARIO("Removing a concrete transformation") {
    GIVEN("A SimpleLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");
        AND_GIVEN("Two diffrent replace transformations and one left trim transformation") {
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<ReplaceTransformation>("design", "factory"));
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<ReplaceTransformation>("label", "text"));
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<LeftTrimTransformation>());

            THEN("The text should be transformed correctly") {
                REQUIRE(simple_label != nullptr);
                REQUIRE(simple_label->getText() == "this text     describes  a    factory pattern!  ");
            }

            WHEN("The concrete ReplaceTransformation is removed") {
                simple_label = LabelDecoratorBase::removeDecoratorFrom(
                    simple_label,
                    std::make_shared<TextTransformationDecorator>(
                        nullptr, std::make_unique<ReplaceTransformation>("label", "text")));

                THEN("The text should be restored to its previous state") {
                    REQUIRE(simple_label != nullptr);
                    REQUIRE(simple_label->getText() == "this label     describes  a    factory pattern!  ");
                }
            }
        }
        AND_GIVEN("Two diffrent CensorTransformations and one RightTrimTransformation") {
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<CensorTransformation>("design"));
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<CensorTransformation>("label"));
            simple_label = std::make_shared<TextTransformationDecorator>(simple_label, std::make_unique<RightTrimTransformation>());

            THEN("The text should be transformed correctly") {
                REQUIRE(simple_label != nullptr);
                REQUIRE(simple_label->getText() == " this *****     describes  a    ****** pattern!");
            }

            WHEN("The concrete CensorTransformation is removed") {
                simple_label = LabelDecoratorBase::removeDecoratorFrom(
                    simple_label,
                    std::make_shared<TextTransformationDecorator>(
                        nullptr, std::make_unique<CensorTransformation>("label")));

                THEN("The text should be restored to its previous state") {
                    REQUIRE(simple_label != nullptr);
                    REQUIRE(simple_label->getText() == " this label     describes  a    ****** pattern!");
                }
            }
        }
    }
}