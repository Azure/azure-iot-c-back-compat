#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.11)
project(azure_iot_c_back_compat)

set(sdk_branch "master" CACHE STRING "Full path to custom HSM repo library")

option(refresh_sdk "set refresh_sdk to get the latest SDK bits from master (default is OFF)" OFF)

# do not add or build any tests of the dependencies
set(run_e2e_tests OFF)
set(run_unittests OFF)
set(skip_samples ON)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/parson)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/umock-c)
#include_directories(${UMOCK_C_INC_FOLDER})

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/c-utility)
#include_directories(${SHARED_UTIL_INC_FOLDER})
#set_platform_files(${CMAKE_CURRENT_LIST_DIR}/deps/c-utility)

enable_testing()

#include("${CMAKE_CURRENT_LIST_DIR}/configs/iot_test_functions.cmake")

set(CLONE_OPTIONS "-q")

#Clone the test submodules if needed
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/testrunnerswitcher/CMakeLists.txt")
    execute_process(COMMAND git clone https://github.com/Azure/azure-c-testrunnerswitcher.git ${CLONE_OPTIONS} ${CMAKE_CURRENT_SOURCE_DIR}/deps/testrunnerswitcher)
endif()
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/ctest/CMakeLists.txt")
    execute_process(COMMAND git clone https://github.com/Azure/azure-ctest.git ${CLONE_OPTIONS} ${CMAKE_CURRENT_SOURCE_DIR}/deps/ctest)
endif()

if (${refresh_sdk} OR NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/c-sdk/CMakeLists.txt")
    execute_process(COMMAND git clone https://github.com/Azure/azure-iot-sdk-c.git ${CLONE_OPTIONS} -b ${sdk_branch} --recursive ${CMAKE_CURRENT_SOURCE_DIR}/deps/c-sdk)
endif()

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/umock-c)
# include_directories(${UMOCK_C_INC_FOLDER})

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/testrunnerswitcher)
# include_directories(${TESTRUNNERSWITCHER_INC_FOLDER})

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/ctest)
# include_directories(${CTEST_INC_FOLDER})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/c-sdk)
set(IOTHUB_REPO_FOLDER ${CMAKE_CURRENT_LIST_DIR}/deps/c-sdk CACHE INTERNAL "Location of the azure c sdk" FORCE)
include_directories(${IOTHUB_REPO_FOLDER}/iothub_client/inc)
include_directories(${IOTHUB_REPO_FOLDER}/provisioning_client/inc)
include_directories(${IOTHUB_REPO_FOLDER}/iothub_service_client/inc)

#????
include_directories(${SHARED_UTIL_INC_FOLDER})

include_directories(./inc)
set(IOTHUB_TEST_INC_FOLDER ${CMAKE_CURRENT_LIST_DIR}/testtools/iothub_test/inc)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/testtools/iothub_test)

# For Now
#set(run_e2e_tests ON)
include("${CMAKE_CURRENT_LIST_DIR}/configs/back_compat_functions.cmake")

add_subdirectory(tests)
