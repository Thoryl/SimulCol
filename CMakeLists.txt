cmake_minimum_required(VERSION 3.5)
project(SimulCol)

# set the module path for "findLib.cmake"
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules/")

# add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# require Eigen
find_package(Eigen3 REQUIRED)
if(${EIGEN3_FOUND})
    message(STATUS "lib EIGEN3 found")
    message(STATUS "  version " ${EIGEN3_VERSION_STRING})
    message(STATUS "  include " ${EIGEN3_INCLUDE_DIR})
endif()

# require lib c3ga
find_package(C3GA)
if(${C3GA_FOUND})
    message(STATUS "lib C3GA found")
    message(STATUS "  include " ${C3GA_INCLUDE_DIRS})
    message(STATUS "  lib     " ${C3GA_LIBRARIES})
else()
    message(STATUS "lib C3GA should be set manually, please uncomment the commented lines in the CMakeLists.txt file")
    #set(C3GA_INCLUDE_DIRS "[path to]/garamon_c3ga/src/")
    set(C3GA_INCLUDE_DIRS "/usr/local/include/c3ga/")
    #set(C3GA_LIBRARIES "[path to]/garamon_c3ga/build/libc3ga.dylib")
    set(C3GA_LIBRARIES "/usr/local/lib/libc3ga.so")

    # for manual setting, check if valid
    if(EXISTS "${C3GA_INCLUDE_DIRS}")
        message(STATUS "include for lib c3ga found: ${C3GA_INCLUDE_DIRS}" )
    else()
        message(FATAL_ERROR "include for lib c3ga invalid or not found: ${C3GA_INCLUDE_DIRS}" )
    endif()

    # for manual setting, check if valid
    if(EXISTS "${C3GA_LIBRARIES}")
        message(STATUS "library c3ga found: ${C3GA_LIBRARIES}" )
    else()
        message(FATAL_ERROR "library c3ga not found: ${C3GA_LIBRARIES}" )
    endif()
endif()


# compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -std=c++14")
#set(CMAKE_CXX_FLAGS_DEBUG_INIT "-g")

# files to compile
file(GLOB_RECURSE include_files include/*.hpp)
message(STATUS "  files " ${include_files})

# files to compile
file(GLOB_RECURSE source_files src/*.cpp)
message(STATUS "  files " ${source_files})

# compile
add_executable(SimulCol ${include_files} ${source_files} main.cpp)

# includes
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${C3GA_INCLUDE_DIRS})

# link
#target_link_libraries(ga_view ${C3GA_LIBRARIES} )