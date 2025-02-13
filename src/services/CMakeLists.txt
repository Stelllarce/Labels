add_library(services STATIC)

set_target_properties(services PROPERTIES OUTPUT_NAME "services")

target_sources(
    services
    PRIVATE
        "LabelPrinter.cpp"
        "CensorTransformationFactory.cpp"
        "LabelFactory.cpp"
        "TransformationFactory.cpp"
        "DecoratorFactory.cpp"
)