add_library(utils STATIC)

set_target_properties(utils PROPERTIES OUTPUT_NAME "utils")

target_sources(
    utils
    PRIVATE
        "HexColor.cpp"
        "StyledFont.cpp"
        "HelpText.cpp"
)