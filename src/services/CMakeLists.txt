add_library(services STATIC)

set_target_properties(services PROPERTIES OUTPUT_NAME "services")

target_sources(
    services
    PRIVATE
        "LabelPrinter.hpp"
        "LabelPrinter.cpp"
)