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
#include "services/LabelPrinter.hpp" // Include the LabelPrinter header

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

    std::string printLabel(std::unique_ptr<Label>& label) {
        std::ostringstream oss;
        LabelPrinter printer;
        printer.print(*label, oss);
        return oss.str();
    }
};

TEST_CASE_METHOD(TransformationTestFixture, "Test Capitalization Transformation") {
    setupSimpleLabel("designing a pattern");
    applyTransformation<CapitalizeTransformation>(simpleLabel);
    REQUIRE(printLabel(simpleLabel) == "Here is a label: Designing a pattern\n");

    setupRichLabel("designing a pattern");
    applyTransformation<CapitalizeTransformation>(richLabel);
    REQUIRE(printLabel(richLabel) == "Here is a label: Designing a pattern\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Censor Transformation") {
    setupSimpleLabel("designing a pattern");
    applyCensorTransformation(simpleLabel, "atter");
    REQUIRE(printLabel(simpleLabel) == "Here is a label: designing a p*****n\n");

    setupRichLabel("designing a pattern");
    applyCensorTransformation(richLabel, "e");
    REQUIRE(printLabel(richLabel) == "Here is a label: d*signing a patt*rn\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Left Trim Transformation") {
    setupSimpleLabel("   designing a pattern");
    applyTransformation<LeftTrimTransformation>(simpleLabel);
    REQUIRE(printLabel(simpleLabel) == "Here is a label: designing a pattern\n");

    setupRichLabel("   designing a pattern");
    applyTransformation<LeftTrimTransformation>(richLabel);
    REQUIRE(printLabel(richLabel) == "Here is a label: designing a pattern\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Right Trim Transformation") {
    setupSimpleLabel("designing a pattern   ");
    applyTransformation<RightTrimTransformation>(simpleLabel);
    REQUIRE(printLabel(simpleLabel) == "Here is a label: designing a pattern\n");

    setupRichLabel("designing a pattern   ");
    applyTransformation<RightTrimTransformation>(richLabel);
    REQUIRE(printLabel(richLabel) == "Here is a label: designing a pattern\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Normalize Space Transformation") {
    setupSimpleLabel("designing  a           pattern");
    applyTransformation<NormalizeSpaceTransformation>(simpleLabel);
    REQUIRE(printLabel(simpleLabel) == "Here is a label: designing a pattern\n");

    setupRichLabel("designing             a  pattern");
    applyTransformation<NormalizeSpaceTransformation>(richLabel);
    REQUIRE(printLabel(richLabel) == "Here is a label: designing a pattern\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Replace Transformation") {
    setupSimpleLabel("designing a pattern");
    applyReplaceTransformation(simpleLabel, "pattern", "anti-pattern");
    REQUIRE(printLabel(simpleLabel) == "Here is a label: designing a anti-pattern\n");

    setupRichLabel("designing a pattern");
    applyReplaceTransformation(richLabel, "atter", "la");
    REQUIRE(printLabel(richLabel) == "Here is a label: designing a plan\n");
}

TEST_CASE_METHOD(TransformationTestFixture, "Test Decorate Transformation") {
    setupSimpleLabel("very pretty text");
    applyTransformation<DecorateTransformation>(simpleLabel);
    REQUIRE(printLabel(simpleLabel) == "Here is a label: -={ very pretty text }=-\n");

    setupRichLabel("very pretty text");
    applyTransformation<DecorateTransformation>(richLabel);
    REQUIRE(printLabel(richLabel) == "Here is a label: -={ very pretty text }=-\n");
}
