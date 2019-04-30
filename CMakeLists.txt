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

enable_testing()

# Submodules
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-c-testrunnerswitcher)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-ctest)

set(AZUREIOT_INC_FOLDER "/usr/local/include/azureiot" "/usr/local/include/azureiot/inc" "/usr/local/include/iothub_service_client")
include_directories(${AZUREIOT_INC_FOLDER})

include_directories(${TESTRUNNERSWITCHER_INC_FOLDER})
include_directories(${CTEST_INC_FOLDER})
include_directories(${UMOCK_C_INC_FOLDER})

include_directories(${SHARED_UTIL_INC_FOLDER})
include_directories(./testtools/iothub_test/inc)
  
include("${CMAKE_CURRENT_LIST_DIR}/configs/back_compat_functions.cmake")

add_subdirectory(tests)
