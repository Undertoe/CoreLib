cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#set(CMAKE_MODULE_PATH /Development/Sandbox/CMakeInfo/)

project(Core
    VERSION 1.0.0
    DESCRIPTION "Testing First Library"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

set(LibsPath /libs/lib64/)
set(HeaderPath /libs/include/)

include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

enable_testing()
include(${CMAKE_CURRENT_LIST_DIR}/tests/CMakeLists.txt)


#add_executable(${PROJECT_NAME} "main.cc")
