#include "catch2/catch_all.hpp"
#include "services/LabelPrinter.hpp"
#include "labels/SimpleLabel.hpp"
#include "labels/RichLabel.hpp"
#include <sstream>

TEST_CASE("General tests", "[LabelPrinter]") {
    std::ostringstream output;
    SECTION("Print SimpleLabel") {
        LabelPrinter labelPrinter;
        SimpleLabel label("Design Patterns");
        REQUIRE_NOTHROW(labelPrinter.print(label, output));
        REQUIRE(output.str() == "Here is a label: Design Patterns\n");
    }
    output.clear();
    SECTION("Print SimpleLabel with empty string") {
        LabelPrinter labelPrinter;
        SimpleLabel label("");
        REQUIRE_NOTHROW(labelPrinter.print(label, output));
        REQUIRE(output.str() == "Here is a label: \n");
    }
}

TEST_CASE("Print a SimpleLabel", "[LabelPrinter]") {
    std::ostringstream output;
    LabelPrinter labelPrinter;
    SimpleLabel label("Design Patterns");
    labelPrinter.print(label, output);
    REQUIRE(output.str() == "Here is a label: Design Patterns\n");
}

TEST_CASE("Print a RichLabel", "[LabelPrinter]") {
    std::ostringstream output;
    LabelPrinter labelPrinter;
    RichLabel label("Design Patterns", "0xFF0000", "Arial:12");
    labelPrinter.print(label, output);
    REQUIRE(output.str() == "Here is a label: Design Patterns Arial:12 0xFF0000\n");
}