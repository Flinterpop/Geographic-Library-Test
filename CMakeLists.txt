cmake_minimum_required (VERSION 3.17.0)
project (geodesictest)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS OFF)


include(FetchContent)
FetchContent_Declare(GeographicLib
  GIT_REPOSITORY https://github.com/geographiclib/geographiclib.git
  GIT_TAG        r2.7
)
FetchContent_MakeAvailable(GeographicLib)

 
 set(GeographicLib_STATIC_LIBRARIES, GeographicLib::GeographicLib_STATIC)

if (NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  # Set a default build type for single-configuration cmake generators
  # if no build type is set.
  set (CMAKE_BUILD_TYPE "Release")
endif ()

add_executable (${PROJECT_NAME} hasMain/hasMain.cpp)
target_link_libraries (${PROJECT_NAME} GeographicLib::GeographicLib)



set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/RunFolder")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )