#include "catch2/catch_all.hpp"
#include "services/LabelPrinter.hpp"
#include <sstream>

TEST_CASE("LabelPrinter test", "[LabelPrinter]") {
    std::ostringstream output;
    SECTION("Print SimpleLabel") {
        LabelPrinter labelPrinter;
        SimpleLabel label("Design Patterns");
        REQUIRE_NOTHROW(labelPrinter.print(label, &output));
        REQUIRE(output.str() == "Design Patterns\n");
    }
    output.clear();
    SECTION("Print SimpleLabel with empty string") {
        LabelPrinter labelPrinter;
        SimpleLabel label("");
        REQUIRE_NOTHROW(labelPrinter.print(label, &output));
        REQUIRE(output.str() == "\n");
    }
}