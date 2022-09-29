cmake_minimum_required(VERSION 3.5)

project(pcap-test LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    ./src/*.cpp
    ./src/*.h
    ./src/protocols/datalink/*.cpp
    ./src/protocols/datalink/*.h
    ./src/protocols/internet/*.cpp
    ./src/protocols/internet/*.h
    ./src/protocols/transport/*.h
    ./src/protocols/transport/*.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

include(cmake/FindPCAP.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME}
  ${PCAP_LIBRARY}
)
