cmake_minimum_required(VERSION 3.5)

project(test-pcap-cli LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_SRC "./../src")
set(TEST_SRC "./src")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SRC})

file(GLOB SOURCES
    ${TEST_SRC}/main.cpp
    ${TEST_SRC}/deserialization_tests.cpp
    
    ${PROJECT_SRC}/sources/*.cpp
    ${PROJECT_SRC}/sources/*.hpp
    ${PROJECT_SRC}/sources/*.h
    ${PROJECT_SRC}/protocol-headers/*.cpp
    ${PROJECT_SRC}/protocol-headers/*.hpp
    ${PROJECT_SRC}/protocol-headers/*.h
    ${PROJECT_SRC}/protocol-headers/datalink/*.cpp
    ${PROJECT_SRC}/protocol-headers/datalink/*.hpp
    ${PROJECT_SRC}/protocol-headers/datalink/*.h
    ${PROJECT_SRC}/protocol-headers/network/*.cpp
    ${PROJECT_SRC}/protocol-headers/network/*.hpp
    ${PROJECT_SRC}/protocol-headers/network/*.h
    ${PROJECT_SRC}/protocol-headers/transport/*.cpp
    ${PROJECT_SRC}/protocol-headers/transport/*.hpp
    ${PROJECT_SRC}/protocol-headers/transport/*.h
    ${PROJECT_SRC}/sinks/*.h
    ${PROJECT_SRC}/sinks/*.h
    ${PROJECT_SRC}/sinks/stdout/*.h
    ${PROJECT_SRC}/sinks/stdout/*.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include(GoogleTest)
enable_testing()

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}")

include(../cmake/FindPCAP.cmake)

target_link_libraries(${CMAKE_PROJECT_NAME} LINK_PUBLIC
  ${PCAP_LIBRARY}
  gtest
)
