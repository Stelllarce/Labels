#include "catch2/catch_all.hpp"
#include "services/CensorTransformationFactory.hpp"

SCENARIO("Creating a CensorTransformationFactory", "[CensorTransformationFactory]") {
    GIVEN("A CensorTransformationFactory with a list of transformations") {
        std::shared_ptr<CensorTransformation> ctf1 = std::make_shared<CensorTransformation>("test");
        std::shared_ptr<CensorTransformation> ctf2 = std::make_shared<CensorTransformation>("word");
        std::shared_ptr<CensorTransformation> ctf3 = std::make_shared<CensorTransformation>("censor");
        CensorTransformationFactory ctf_factory({ctf1, ctf2, ctf3});

        WHEN("A transformation is requested") {
            THEN("The factory will return the transformation if it exists") {
                REQUIRE(ctf_factory.createCensorTransformation("test") == ctf1);
                REQUIRE(ctf_factory.createCensorTransformation("word") == ctf2);
            }
            THEN("Third word is more than 4 letters so a new one will be constructed") {
                REQUIRE(ctf_factory.createCensorTransformation("censor")->getCensorWord() == "censor");
            }
            THEN("The shared pointer internal count will increase if the transformation exists") {
                std::shared_ptr<CensorTransformation> ctf4 = ctf_factory.createCensorTransformation("test");
                REQUIRE(ctf1.use_count() == 3);
            }
            THEN("The factory will create a new transformation if it does not exist") {
                std::shared_ptr<CensorTransformation> ctf4 = ctf_factory.createCensorTransformation("new");
                REQUIRE(ctf4->getCensorWord() == "new");
            }
        }
        WHEN("A word with more than 4 characters is requested") {
            THEN("The factory will create a new transformation") {
                std::shared_ptr<CensorTransformation> ctf4 = ctf_factory.createCensorTransformation("longword");
                REQUIRE(ctf4->getCensorWord() == "longword");
            }
        }
    }
}