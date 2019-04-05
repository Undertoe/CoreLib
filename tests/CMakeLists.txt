cmake_minimum_required(VERSION 3.5)

#set(GTEST_ROOT "/usr/local/lib/" CACHE PATH "Path to Googletest")
set(lgtest "/usr/local/lib/libgtest.a")
set(lgtestmain "/usr/local/lib/libgtest_main.a")

find_package(GTest REQUIRED)

INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIR})


file(GLOB srcFiles "*.cc")
add_executable(test_${PROJECT_NAME}
    ${CMAKE_CURRENT_LIST_DIR}/test_notification.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_container_helpers.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_error.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_random_device.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_type_converter.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_AddressType.cc
    ${CMAKE_CURRENT_LIST_DIR}/test_buffer.cc
#    ${CMAKE_CURRENT_LIST_DIR}/test_complex.cc
    )


target_include_directories(test_${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)
#target_link_libraries(test_${PROJECT_NAME} PRIVATE gtest gtest_main)
target_link_libraries(test_${PROJECT_NAME} PRIVATE ${lgtest} ${lgtestmain})
target_link_libraries(test_${PROJECT_NAME} PRIVATE pthread)
target_link_libraries(test_${PROJECT_NAME} PRIVATE ${PROJECT_NAME})

add_custom_command(TARGET test_${PROJECT_NAME}
    POST_BUILD
    COMMAND test_${PROJECT_NAME} -c $<CONFIGURATION> --output-on-failure)


