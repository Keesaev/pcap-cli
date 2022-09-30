cmake_minimum_required(VERSION 3.5)

project(pcap-test LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES
    ./src/*.cpp
    ./src/*.h
    ./src/protocol-headers/*.cpp
    ./src/protocol-headers/*.hpp
    ./src/protocol-headers/*.h
    ./src/protocol-headers/datalink/*.cpp
    ./src/protocol-headers/datalink/*.hpp
    ./src/protocol-headers/datalink/*.h
    ./src/protocol-headers/network/*.cpp
    ./src/protocol-headers/network/*.hpp
    ./src/protocol-headers/network/*.h
    ./src/protocol-headers/transport/*.cpp
    ./src/protocol-headers/transport/*.hpp
    ./src/protocol-headers/transport/*.h
)

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

include(cmake/FindPCAP.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME}
  ${PCAP_LIBRARY}
)
