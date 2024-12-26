# Executable target for the unit tests
add_executable(unit-tests)

target_link_libraries(
    unit-tests
    PRIVATE
        labels
        services
        utils
        transformations
        decorators
        Catch2::Catch2WithMain
)

target_sources(
    unit-tests
    PRIVATE
        "label-tests/test-simple-label.cpp"
        "label-tests/test-rich-label.cpp"
        "service-tests/test-label-printer.cpp"
        "utils-tests/test-font.cpp"
        "transformations-tests/test-capitalization.cpp"
        "transformations-tests/test-left-trim.cpp"
        "transformations-tests/test-right-trim.cpp"
        "transformations-tests/test-normalize-space.cpp"
        "transformations-tests/test-decorate.cpp"
        "transformations-tests/test-censor.cpp"
        "transformations-tests/test-replace.cpp"
        "decorators-tests/test-text-transformation-individual.cpp"
        "decorators-tests/test-text-transformation-stacked.cpp"
)

# Automatically register all tests
catch_discover_tests(unit-tests)
