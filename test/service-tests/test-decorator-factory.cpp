#include "catch2/catch_all.hpp"
#include "services/DecoratorFactory.hpp"
#include "labels/SimpleLabel.hpp"

SCENARIO("Creating decorators using DecoratorFactory") {
    GIVEN("A simple label and various decorator requests") {
        WHEN("Creating a simple transformation decorator") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            auto decorated = DecoratorFactory::createDecorator(
                "simple",
                std::move(label),
                "capitalize"
            );

            THEN("The decorator should be created and work correctly") {
                REQUIRE(decorated != nullptr);
                REQUIRE(decorated->getText() == "Hello world");
            }
        }

        WHEN("Creating a cycling transformation decorator") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            auto decorated = DecoratorFactory::createDecorator(
                "cycling",
                std::move(label),
                "capitalize censor:world"
            );

            THEN("The decorator should be created and work correctly") {
                REQUIRE(decorated != nullptr);
                std::string initial = decorated->getText();
                std::string next = decorated->getText();
                REQUIRE(initial != next);  // Should cycle between transformations
            }
        }

        WHEN("Creating a random transformation decorator") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            auto decorated = DecoratorFactory::createDecorator(
                "random",
                std::move(label),
                "capitalize censor:world normalize_space"
            );

            THEN("The decorator should be created") {
                REQUIRE(decorated != nullptr);
                // Note: Can't test randomness effectively, but can verify it doesn't crash
                decorated->getText();
                decorated->getText();
            }
        }

        WHEN("Creating a decorator with invalid type") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            auto decorated = DecoratorFactory::createDecorator(
                "invalid_type",
                std::move(label),
                "capitalize"
            );

            THEN("The creation should fail") {
                REQUIRE(decorated == nullptr);
            }
        }

        WHEN("Creating a decorator with invalid transformation command") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("hello world");
            auto decorated = DecoratorFactory::createDecorator(
                "simple",
                std::move(label),
                "invalid_command"
            );

            THEN("The creation should fail") {
                REQUIRE(decorated == nullptr);
            }
        }
    }
}

SCENARIO("Testing complex decorator combinations") {
    GIVEN("A label and multiple transformations") {
        WHEN("Creating a cycling decorator with multiple transformations") {
            std::unique_ptr<Label> label = std::make_unique<SimpleLabel>("  hello  world  ");
            auto decorated = DecoratorFactory::createDecorator(
                "cycling",
                std::move(label),
                "left_trim right_trim normalize_space capitalize"
            );

            THEN("The decorator should apply transformations in sequence") {
                REQUIRE(decorated != nullptr);
                std::vector<std::string> results;
                for (int i = 0; i < 4; ++i) {
                    results.push_back(decorated->getText());
                }
                // Should see different results as it cycles
                REQUIRE(results[0] != results[1]);
                REQUIRE(results[1] != results[2]);
            }
        }
    }
}