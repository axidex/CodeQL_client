macro(he_add_test SUITE_NAME RESOURCES_BOOL)
    file(GLOB ${SUITE_NAME}_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    )

    add_executable(${SUITE_NAME} ${${SUITE_NAME}_SOURCES})

    if(${RESOURCES_BOOL})
        file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/../bin/utests/)
    endif()

    target_link_libraries(${SUITE_NAME} PRIVATE UTest)
endmacro()

macro(he_add_module PROJECT_LINK_NAME MODULE_NAME MODULE_FULL_PATH)
    file(GLOB ${MODULE_NAME}_SOURCES
        "${MODULE_FULL_PATH}/src/*.cpp"
    )

    if (UNIX AND NOT APPLE)
        file(GLOB ${MODULE_NAME}_PLATFORM_SOURCES
            "${MODULE_FULL_PATH}/src/platform/linux/*.cpp"
        )
    elseif(WIN32)
        file(GLOB ${MODULE_NAME}_PLATFORM_SOURCES
            "${MODULE_FULL_PATH}/src/platform/win/*.cpp"
        )
    elseif(APPLE)
        file(GLOB ${MODULE_NAME}_PLATFORM_SOURCES
            "${MODULE_FULL_PATH}/src/platform/mac/*.cpp"
        )
    endif()

    target_sources(${PROJECT_LINK_NAME} PRIVATE ${${MODULE_NAME}_SOURCES} ${${MODULE_NAME}_PLATFORM_SOURCES})
endmacro()

macro(he_add_engine_module MODULE_NAME)
    he_add_module(${ENGINE_PROJECT_NAME} ${MODULE_NAME} ${MODULE_NAME})
endmacro()