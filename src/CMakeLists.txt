cmake_minimum_required(VERSION 3.7)

if(NOT DEFINED CMAKE_DEBUG_POSTFIX)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

project(CoreLib)

add_library(${PROJECT_NAME} STATIC "")
add_library(CORE::${PROJECT_NAME} ALIAS ${PROJECT_NAME})


target_sources(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/notification.cc
#    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/complex.cc
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/error.cc
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/random_device.cc
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/addresstype.cc
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/buffer.cc
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/vmemodes.cc
    )

file(GLOB headers "${CMAKE_CURRENT_LIST_DIR}/*.hh")

add_compile_options("$<$<CONFIG:RELEASE>:-W;-Wall;-O3;-pedantic>")
add_compile_options("$<$<CONFIG:DEBUG>:-W;-Wall;-O0;-g;-pedantic>")

target_link_libraries(${PROJECT_NAME} PUBLIC
    )


if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

foreach(header ${headers})
    install(
        FILES ${header} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )
endforeach()

install(TARGETS
    ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT lib
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT lib
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT bin
#    ${headers} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT include
    )

