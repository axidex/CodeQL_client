# Executable for run tests
file(GLOB UTEST_SOURCES
    "${PROJECT_BINARY_DIR}/../Engine/UTest/src/UTest.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin/)

add_executable(HUTest ${UTEST_SOURCES})

file(GLOB UTEST_LIB_SOURCES
    "src/TestSuite.cpp"
    "src/TestReporter.cpp"
)

add_library(UTest SHARED ${UTEST_LIB_SOURCES})

he_add_module(UTest Core ${PROJECT_SOURCE_DIR}/Engine/Core/)
he_add_module(UTest Utils ${PROJECT_SOURCE_DIR}/Engine/Utils/)