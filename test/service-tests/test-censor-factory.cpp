#include "catch2/catch_all.hpp"
#include "decorators/TextTransformationDecorator.hpp"
#include "labels/SimpleLabel.hpp"
#include "services/CensorTransformationFactory.hpp"

SCENARIO("Basic censoring functionality with flyweight factory") {
    GIVEN("A CensorTransformationFactory and a simple label") {
        CensorTransformationFactory factory;
        std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("bad mad sad");

        WHEN("A censor transformation is created for 'bad'") {
            auto censor_bad = factory.createCensorTransformation("bad");
            label = std::make_unique<TextTransformationDecorator>(
                std::move(label), 
                std::unique_ptr<TextTransformation>(censor_bad->clone())
            );

            THEN("Only 'bad' should be censored") {
                REQUIRE(label->getText() == "*** mad sad");
            }

            AND_WHEN("Another censor transformation is added for 'mad'") {
                auto censor_mad = factory.createCensorTransformation("mad");
                label = std::make_unique<TextTransformationDecorator>(
                    std::move(label), 
                    std::unique_ptr<TextTransformation>(censor_mad->clone())
                );

                THEN("Both 'bad' and 'mad' should be censored") {
                    REQUIRE(label->getText() == "*** *** sad");
                }

                AND_WHEN("A final censor transformation is added for 'sad'") {
                    auto censor_sad = factory.createCensorTransformation("sad");
                    label = std::make_unique<TextTransformationDecorator>(
                        std::move(label), 
                        std::unique_ptr<TextTransformation>(censor_sad->clone())
                    );

                    THEN("All words should be censored") {
                        REQUIRE(label->getText() == "*** *** ***");
                    }
                }
            }
        }
    }
}

SCENARIO("Testing flyweight letter reuse") {
    GIVEN("A CensorTransformationFactory") {
        CensorTransformationFactory factory;
        
        WHEN("Creating transformations for words with common letters") {
            // These words share 'a' and 'd'
            auto trans1 = factory.createCensorTransformation("bad");
            auto trans2 = factory.createCensorTransformation("mad");
            auto trans3 = factory.createCensorTransformation("dad");

            std::unique_ptr<Label> label1 = std::make_unique<SimpleLabel>("bad person");
            std::unique_ptr<Label> label2 = std::make_unique<SimpleLabel>("mad person");
            std::unique_ptr<Label> label3 = std::make_unique<SimpleLabel>("dad person");

            label1 = std::make_unique<TextTransformationDecorator>(
                std::move(label1), 
                std::unique_ptr<TextTransformation>(trans1->clone())
            );
            label2 = std::make_unique<TextTransformationDecorator>(
                std::move(label2), 
                std::unique_ptr<TextTransformation>(trans2->clone())
            );
            label3 = std::make_unique<TextTransformationDecorator>(
                std::move(label3), 
                std::unique_ptr<TextTransformation>(trans3->clone())
            );

            THEN("All words should be censored correctly") {
                REQUIRE(label1->getText() == "*** person");
                REQUIRE(label2->getText() == "*** person");
                REQUIRE(label3->getText() == "*** person");
            }
        }
    }
}

SCENARIO("Testing censoring with repeated letters") {
    GIVEN("A CensorTransformationFactory") {
        CensorTransformationFactory factory;
        
        WHEN("Creating a transformation for a word with repeated letters") {
            auto trans = factory.createCensorTransformation("deed");
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("good deed done");
            label = std::make_unique<TextTransformationDecorator>(
                std::move(label), 
                std::unique_ptr<TextTransformation>(trans->clone())
            );

            THEN("The word should be censored correctly") {
                REQUIRE(label->getText() == "good **** done");
            }
        }
    }
}

SCENARIO("Testing case sensitivity in censoring") {
    GIVEN("A CensorTransformationFactory") {
        CensorTransformationFactory factory;
        
        WHEN("Creating transformations for words with different cases") {
            auto trans_lower = factory.createCensorTransformation("bad");
            auto trans_upper = factory.createCensorTransformation("BAD");
            
            std::unique_ptr<Label> label1 = std::make_unique<SimpleLabel>("bad BAD Bad bAd");
            std::unique_ptr<Label> label2 = std::make_unique<SimpleLabel>("BAD bad BAd baD");
            
            label1 = std::make_unique<TextTransformationDecorator>(
                std::move(label1), 
                std::unique_ptr<TextTransformation>(trans_lower->clone())
            );
            label2 = std::make_unique<TextTransformationDecorator>(
                std::move(label2), 
                std::unique_ptr<TextTransformation>(trans_upper->clone())
            );

            THEN("Only exact case matches should be censored") {
                REQUIRE(label1->getText() == "*** BAD Bad bAd");
                REQUIRE(label2->getText() == "*** bad BAd baD");
            }
        }
    }
}

SCENARIO("Testing empty and whitespace words") {
    GIVEN("A CensorTransformationFactory") {
        CensorTransformationFactory factory;
        
        WHEN("Creating transformations for empty and whitespace strings") {
            auto trans_empty = factory.createCensorTransformation("");
            auto trans_space = factory.createCensorTransformation(" ");
            
            std::unique_ptr<Label> label1 = std::make_unique<SimpleLabel>("test test");
            std::unique_ptr<Label> label2 = std::make_unique<SimpleLabel>("test*test");
            
            label1 = std::make_unique<TextTransformationDecorator>(
                std::move(label1), 
                std::unique_ptr<TextTransformation>(trans_empty->clone())
            );
            label2 = std::make_unique<TextTransformationDecorator>(
                std::move(label2), 
                std::unique_ptr<TextTransformation>(trans_space->clone())
            );

            THEN("The text should remain unchanged") {
                REQUIRE(label1->getText() == "test test");
                REQUIRE(label2->getText() == "test test");
            }
        }
    }
}