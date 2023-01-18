cmake_minimum_required(VERSION 3.5)

project(test-pcap-cli LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(PROJECT_SRC_DIR "./../src")
set(TEST_SRC_DIR "./src")
set(RAPID_CSV_DIR "./rapidcsv")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
  ${PROJECT_SRC_DIR}
  ${RAPID_CSV_DIR}/src
)

file(GLOB SOURCES
    ${TEST_SRC_DIR}/main.cpp
    ${TEST_SRC_DIR}/deserialization_tests.cpp

    ${RAPID_CSV_DIR}/src/rapidcsv.h
    
    ${PROJECT_SRC_DIR}/sources/*.cpp
    ${PROJECT_SRC_DIR}/sources/*.hpp
    ${PROJECT_SRC_DIR}/sources/*.h
    ${PROJECT_SRC_DIR}/protocol-headers/*.cpp
    ${PROJECT_SRC_DIR}/protocol-headers/*.hpp
    ${PROJECT_SRC_DIR}/protocol-headers/*.h
    ${PROJECT_SRC_DIR}/protocol-headers/datalink/*.cpp
    ${PROJECT_SRC_DIR}/protocol-headers/datalink/*.hpp
    ${PROJECT_SRC_DIR}/protocol-headers/datalink/*.h
    ${PROJECT_SRC_DIR}/protocol-headers/network/*.cpp
    ${PROJECT_SRC_DIR}/protocol-headers/network/*.hpp
    ${PROJECT_SRC_DIR}/protocol-headers/network/*.h
    ${PROJECT_SRC_DIR}/protocol-headers/transport/*.cpp
    ${PROJECT_SRC_DIR}/protocol-headers/transport/*.hpp
    ${PROJECT_SRC_DIR}/protocol-headers/transport/*.h
    ${PROJECT_SRC_DIR}/sinks/*.h
    ${PROJECT_SRC_DIR}/sinks/stdout/*.h
    ${PROJECT_SRC_DIR}/sinks/stdout/*.cpp
    ${PROJECT_SRC_DIR}/sinks/test/*.h
    ${PROJECT_SRC_DIR}/sinks/test/*.cpp

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
