add_library(transformations STATIC)

set_target_properties(transformations PROPERTIES OUTPUT_NAME "transformations")

target_sources(
    transformations
    PRIVATE
        "CapitalizeTransformation.cpp"       
        "LeftTrimTransformation.cpp"
        "RightTrimTransformation.cpp"
        "NormalizeSpaceTransformation.cpp"
        "DecorateTransformation.cpp"
        "CensorTransformation.cpp"
        "ReplaceTransformation.cpp"
        "CompositeTransformation.cpp"
)