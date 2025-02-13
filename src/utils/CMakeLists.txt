add_library(utils STATIC)

set_target_properties(utils PROPERTIES OUTPUT_NAME "utils")

target_sources(
    utils
    PRIVATE
        "HelpText.cpp"
        "CensoredLetter.cpp"
)