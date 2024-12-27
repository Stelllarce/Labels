#include "catch2/catch_all.hpp"
#include "decorators/TextTransformationDecorator.hpp"
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
#include "services/LabelPrinter.hpp"

SCENARIO("Applying sequential transformations on labels using TransformationDecorator") {
    
    GIVEN("A SimpleLabel and a RichLabel") {
        std::shared_ptr<Label> simple_label = std::make_shared<SimpleLabel>(" this label     describes  a    design pattern!  ");
        std::shared_ptr<Label> rich_label = std::make_shared<RichLabel>(
            "   this is  another      label, that uses  a rich  font! ",
            Color(0x00FF00), 
            Font("Arial", 12)
        );

        LabelPrinter printer;

        WHEN("A LeftTrimTransformation is applied") {
            simple_label = std::make_shared<TextTransformationDecorator>(
                std::move(simple_label), std::make_unique<LeftTrimTransformation>());
            rich_label = std::make_shared<TextTransformationDecorator>(
                std::move(rich_label), std::make_unique<LeftTrimTransformation>());

            THEN("Leading spaces should be removed") {
                std::ostringstream oss1;
                printer.print(*simple_label, oss1);
                REQUIRE(oss1.str() == "Here is a label: this label     describes  a    design pattern!  \n");

                std::ostringstream oss2;
                printer.print(*rich_label, oss2);
                REQUIRE(oss2.str() == "Here is a label: this is  another      label, that uses  a rich  font!  Arial 12 0xFF00\n");
            }

            WHEN("A CapitalizeTransformation is applied") {
                simple_label = std::make_shared<TextTransformationDecorator>(
                    std::move(simple_label), std::make_unique<CapitalizeTransformation>());
                rich_label = std::make_shared<TextTransformationDecorator>(
                    std::move(rich_label), std::make_unique<CapitalizeTransformation>());

                THEN("The text should start with an uppercase letter") {
                    std::ostringstream oss;
                    printer.print(*simple_label, oss);
                    REQUIRE(oss.str() == "Here is a label: This label     describes  a    design pattern!  \n");

                    oss.str("");
                    printer.print(*rich_label, oss);
                    REQUIRE(oss.str() == "Here is a label: This is  another      label, that uses  a rich  font!  Arial 12 0xFF00\n");
                }

                WHEN("A NormalizeSpaceTransformation is applied") {
                    simple_label = std::make_shared<TextTransformationDecorator>(
                        std::move(simple_label), std::make_unique<NormalizeSpaceTransformation>());
                    rich_label = std::make_shared<TextTransformationDecorator>(
                        std::move(rich_label), std::make_unique<NormalizeSpaceTransformation>());

                    THEN("Consecutive spaces should be reduced to a single space") {
                        std::ostringstream oss;
                        printer.print(*simple_label, oss);
                        REQUIRE(oss.str() == "Here is a label: This label describes a design pattern! \n");

                        oss.str("");
                        printer.print(*rich_label, oss);
                        REQUIRE(oss.str() == "Here is a label: This is another label, that uses a rich font!  Arial 12 0xFF00\n");
                    }

                    WHEN("A RightTrimTransformation is applied") {
                        simple_label = std::make_shared<TextTransformationDecorator>(
                            std::move(simple_label), std::make_unique<RightTrimTransformation>());
                        rich_label = std::make_shared<TextTransformationDecorator>(
                            std::move(rich_label), std::make_unique<RightTrimTransformation>());

                        THEN("Trailing spaces should be removed") {
                            std::ostringstream oss;
                            printer.print(*simple_label, oss);
                            REQUIRE(oss.str() == "Here is a label: This label describes a design pattern!\n");

                            oss.str("");
                            printer.print(*rich_label, oss);
                            REQUIRE(oss.str() == "Here is a label: This is another label, that uses a rich font! Arial 12 0xFF00\n");
                        }
                        WHEN("A DecorateTransformation is applied") {
                            simple_label = std::make_shared<TextTransformationDecorator>(
                                std::move(simple_label), std::make_unique<DecorateTransformation>());
                            rich_label = std::make_shared<TextTransformationDecorator>(
                                std::move(rich_label), std::make_unique<DecorateTransformation>());

                            THEN("The text should be enclosed in square brackets") {
                                std::ostringstream oss;
                                printer.print(*simple_label, oss);
                                REQUIRE(oss.str() == "Here is a label: -={ This label describes a design pattern! }=-\n");

                                oss.str("");
                                printer.print(*rich_label, oss);
                                REQUIRE(oss.str() == "Here is a label: -={ This is another label, that uses a rich font! }=- Arial 12 0xFF00\n");
                            }
                        }
                    }
                }
            }
        }
    }
}