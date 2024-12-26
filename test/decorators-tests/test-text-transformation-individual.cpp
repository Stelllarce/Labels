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

class TransformationTestFixture {
protected:
    std::unique_ptr<Label> simpleLabel;
    std::unique_ptr<Label> richLabel;

    void setupSimpleLabel(const std::string& text) {
        simpleLabel = std::make_unique<SimpleLabel>(text);
    }

    void setupRichLabel(const std::string& text) {
        richLabel = std::make_unique<RichLabel>(text, Color(0xFFFFFF), Font("Arial", 12));
    }

    template <typename Transformation>
    void applyTransformation(std::unique_ptr<Label>& label) {
        label = std::make_unique<TextTransformationDecorator>(
            std::move(label), std::make_unique<Transformation>()
        );
    }

    void applyCensorTransformation(std::unique_ptr<Label>& label, const std::string& toCensor) {
        label = std::make_unique<TextTransformationDecorator>(
            std::move(label), std::make_unique<CensorTransformation>(toCensor)
        );
    }

    void applyReplaceTransformation(std::unique_ptr<Label>& label, const std::string& from, const std::string& to) {
        label = std::make_unique<TextTransformationDecorator>(
            std::move(label), std::make_unique<ReplaceTransformation>(from, to)
        );
    }
};

TEST_CASE_METHOD(TransformationTestFixture, "Test Capitalization Transformation") {
    setupSimpleLabel("designing a pattern");
    applyTransformation<CapitalizeTransformation>(simpleLabel);
    REQUIRE(simpleLabel->getText() == "Designing a pattern");

    setupRichLabel("designing a pattern");
    applyTransformation<CapitalizeTransformation>(richLabel);
    REQUIRE(richLabel->getText() == "Designing a pattern");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Censor Transformation") {
    setupSimpleLabel("designing a pattern");
    applyCensorTransformation(simpleLabel, "atter");
    REQUIRE(simpleLabel->getText() == "designing a p*****n");

    setupRichLabel("designing a pattern");
    applyCensorTransformation(richLabel, "e");
    REQUIRE(richLabel->getText() == "d*signing a patt*rn");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Left Trim Transformation") {
    setupSimpleLabel("   designing a pattern");
    applyTransformation<LeftTrimTransformation>(simpleLabel);
    REQUIRE(simpleLabel->getText() == "designing a pattern");

    setupRichLabel("   designing a pattern");
    applyTransformation<LeftTrimTransformation>(richLabel);
    REQUIRE(richLabel->getText() == "designing a pattern");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Right Trim Transformation") {
    setupSimpleLabel("designing a pattern   ");
    applyTransformation<RightTrimTransformation>(simpleLabel);
    REQUIRE(simpleLabel->getText() == "designing a pattern");

    setupRichLabel("designing a pattern   ");
    applyTransformation<RightTrimTransformation>(richLabel);
    REQUIRE(richLabel->getText() == "designing a pattern");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Normalize Space Transformation") {
    setupSimpleLabel("designing  a           pattern");
    applyTransformation<NormalizeSpaceTransformation>(simpleLabel);
    REQUIRE(simpleLabel->getText() == "designing a pattern");

    setupRichLabel("designing             a  pattern");
    applyTransformation<NormalizeSpaceTransformation>(richLabel);
    REQUIRE(richLabel->getText() == "designing a pattern");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Replace Transformation") {
    setupSimpleLabel("designing a pattern");
    applyReplaceTransformation(simpleLabel, "pattern", "anti-pattern");
    REQUIRE(simpleLabel->getText() == "designing a anti-pattern");

    setupRichLabel("designing a pattern");
    applyReplaceTransformation(richLabel, "atter", "la");
    REQUIRE(richLabel->getText() == "designing a plan");
}
