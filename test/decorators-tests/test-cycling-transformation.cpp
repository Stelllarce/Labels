#include "catch2/catch_all.hpp"
#include "decorators/CyclingTransformationsDecorator.hpp"
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

SCENARIO("Applying the CycleDecorator's transformations contigiously on a simple label") {
    GIVEN("A SimpleLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this is a simple  label ");

        THEN("The simple label should have been created correctly") {
            REQUIRE(simple_label != nullptr);
            REQUIRE(simple_label->getText() == " this is a simple  label ");
        }

        AND_GIVEN("A vector of tranformations") {
            std::vector<std::shared_ptr<TextTransformation>> transformations;
            transformations.push_back(std::make_shared<LeftTrimTransformation>());
            transformations.push_back(std::make_shared<CensorTransformation>("is"));
            transformations.push_back(std::make_shared<CapitalizeTransformation>());
            transformations.push_back(std::make_shared<RightTrimTransformation>());
            transformations.push_back(std::make_shared<NormalizeSpaceTransformation>());
            transformations.push_back(std::make_shared<ReplaceTransformation>("simple", "complex"));
            transformations.push_back(std::make_shared<DecorateTransformation>());
            
            WHEN("A CyclingTransformationsDecorator is applied") {

                simple_label = std::make_shared<CyclingTransformationsDecorator>(
                    std::move(simple_label), transformations);

                THEN("A left trim should be applied") {
                    REQUIRE(simple_label->getText() == "this is a simple  label ");
                    
                    AND_THEN("is should be censored"){
                        REQUIRE(simple_label->getText() == " th** ** a simple  label ");

                        AND_THEN("Capitalization should be applied, but nothing will change") {
                            REQUIRE(simple_label->getText() == " this is a simple  label ");

                            AND_THEN("Right trim should be applied") {
                                REQUIRE(simple_label->getText() == " this is a simple  label");

                                AND_THEN("Spaces should be normalized") {
                                    REQUIRE(simple_label->getText() == " this is a simple label ");

                                    AND_THEN("Simple should be replaced with complex") {
                                        REQUIRE(simple_label->getText() == " this is a complex  label ");

                                        AND_THEN("THe text should be decorated") {
                                            REQUIRE(simple_label->getText() == "-={  this is a simple  label  }=-");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
