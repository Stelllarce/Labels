add_library(labels STATIC)

set_target_properties(labels PROPERTIES OUTPUT_NAME "labels")

target_sources(
    labels
    PRIVATE
        "SimpleLabel.cpp"
        "RichLabel.cpp"
        "CustomLabel.cpp"
)