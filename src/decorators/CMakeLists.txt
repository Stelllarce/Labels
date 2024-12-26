add_library(decorators STATIC)

set_target_properties(decorators PROPERTIES OUTPUT_NAME "decorators")

target_sources(
    decorators
    PRIVATE
        "LabelDecoratorBase.cpp"
        "TextTransformationDecorator.cpp"
)