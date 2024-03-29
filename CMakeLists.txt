cmake_minimum_required(VERSION 3.5)

project(pcap-cli LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vscode stuff
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

file(GLOB SOURCES
    ./src/*.cpp
    ./src/*.h
    ./src/sources/*.cpp
    ./src/sources/*.hpp
    ./src/sources/*.h
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
    ./src/sinks/*.h
    ./src/sinks/stdout/*.h
    ./src/sinks/stdout/*.cpp
)

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC 
  ${PROJECT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(cmake/FindPCAP.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME}
  ${PCAP_LIBRARY}
)
