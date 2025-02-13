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
        "label-tests/test-custom-label.cpp"
        "service-tests/test-label-printer.cpp"
        "service-tests/test-censor-factory.cpp"
        "service-tests/test-decorator-factory.cpp"
        "service-tests/test-transformation-factory.cpp"
        "service-tests/test-label-factory.cpp"
        "transformations-tests/test-capitalization.cpp"
        "transformations-tests/test-left-trim.cpp"
        "transformations-tests/test-right-trim.cpp"
        "transformations-tests/test-normalize-space.cpp"
        "transformations-tests/test-decorate.cpp"
        "transformations-tests/test-censor.cpp"
        "transformations-tests/test-replace.cpp"
        "transformations-tests/test-operator-equals.cpp"
        "transformations-tests/test-composite.cpp"
        "decorators-tests/test-text-transformation-individual.cpp"
        "decorators-tests/test-text-transformation-stacked.cpp"
        "decorators-tests/test-random-transformation.cpp"
        "decorators-tests/test-cycling-transformation.cpp"
        "decorators-tests/test-operator-equals.cpp"
        "decorators-tests/test-decorator-removal.cpp"
)

# Automatically register all tests
catch_discover_tests(unit-tests)
