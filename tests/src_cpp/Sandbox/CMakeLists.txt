cmake_minimum_required(VERSION 3.13)

set(SANDBOX_PROJECT_NAME HSandbox)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../bin/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB SANDBOX_SOURCES 
    "*.cpp" 
    "Game/src/*.cpp"
)

# Link Engine Library
if(SANDBOX_ONLY)
    include_directories(${PROJECT_BINARY_DIR}/../Engine/Core/include)

    add_library(HEngine SHARED IMPORTED)

    if(UNIX)
        set_property(TARGET HEngine PROPERTY
            IMPORTED_LOCATION
                ${PROJECT_BINARY_DIR}/../bin/libHEngine.so          
        )
    elseif(WIN32)
        set_property(TARGET HEngine PROPERTY
            IMPORTED_LOCATION
                ${PROJECT_BINARY_DIR}/../bin/libHEngine.dll         
        )
    endif()
endif()

# Create an executable
add_executable(${SANDBOX_PROJECT_NAME} ${SANDBOX_SOURCES})

# Link include directories
target_include_directories(${SANDBOX_PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/../Engine/vendor/spdlog/include)
target_include_directories(${SANDBOX_PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR}/../Engine)

target_link_libraries(${SANDBOX_PROJECT_NAME} HEngine)