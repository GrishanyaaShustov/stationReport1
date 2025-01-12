cmake_minimum_required(VERSION 3.30)
project(stationReport1)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/headers)

add_executable(stationReport1 main.cpp
        headers/stationReport.h
        src/stationReport.cpp
        src/createReport.cpp
        headers/createReport.h
        headers/indexesArrayFuncs.h
        src/indexesArrayFuncs.cpp
        headers/searchFuncs.h
        src/searchFunc.cpp
        buildMainFuncs.h
        buildMainFuncs.cpp)
