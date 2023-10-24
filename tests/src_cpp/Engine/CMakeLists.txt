cmake_minimum_required(VERSION 3.13)

set(ENGINE_PROJECT_NAME HEngine)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# ----------------------- Resources ----------------------- #

configure_file(Core/resources/hoopoe.cfg ${PROJECT_SOURCE_DIR}/bin/hoopoe.cfg COPYONLY)

# -------------------- Engine Library --------------------- #

add_library(${ENGINE_PROJECT_NAME} SHARED)

he_add_engine_module(Core)
he_add_engine_module(Utils)

target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE UTest)

# -------------------- Include paths ---------------------- #

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC vendor/spdlog/include)

# ------------------------- UTest ------------------------- #

if(UTEST)
    # UTest main
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest)

    # Tests
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/utests)

    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/UTest/test)
    add_subdirectory(${PROJECT_SOURCE_DIR}/Engine/Core/test)
    
endif()