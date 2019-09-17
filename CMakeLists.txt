#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.11)
project(azure_iot_c_back_compat)

set(sdk_branch "master" CACHE STRING "Full path to custom HSM repo library")

option(use_installed_dependencies "use_installed_dependencies to ON to use installed packages instead of building dependencies from submodules" OFF)

enable_testing()

if (${use_installed_dependencies})
    set(AZUREIOT_INC_FOLDER
        "/usr/local/include/azureiot"
        "/usr/local/include/iothub_service_client"
        "/usr/local/include/azure_prov_client"
    )
else()
    # do not add or build any tests of the dependencies
    set(run_e2e_tests OFF)
    set(run_unittests OFF)
    set(skip_samples ON)
    set(use_prov_client ON)
    # Set the custom HSM that we will be using
    set(hsm_type_custom ON)

    if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/CMakeLists.txt")
        message("Cloning Azure Iot SDK C...")
        execute_process(COMMAND git clone https://github.com/Azure/azure-iot-sdk-c.git -q ${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c)
        execute_process(COMMAND git submodule update --init WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c)
    endif()
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c")
    set(AZUREIOT_INC_FOLDER
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/iothub_client/inc"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/iothub_service_client/inc"
    )
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/deps/parson)
    include_directories("${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/c-utility/inc")

    # Need to use the azure deps for testrunnerswitcher and ctest so you don't have to update these
    # everytime you update the sdk
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/deps/azure-c-testrunnerswitcher)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/azure-iot-sdk-c/deps/azure-ctest)
endif()

IF(WIN32)
    #windows needs this define
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
ENDIF(WIN32)

message("shared util directory ${TESTRUNNERSWITCHER_INC_FOLDER}")

include_directories(${AZUREIOT_INC_FOLDER})
include_directories(${TESTRUNNERSWITCHER_INC_FOLDER})
include_directories(${CTEST_INC_FOLDER})
include_directories(${UMOCK_C_INC_FOLDER})
include_directories(${MACRO_UTILS_INC_FOLDER})

include_directories(${DEV_AUTH_MODULES_CLIENT_INC_FOLDER})
include_directories(${PROVISIONING_SERVICE_CLIENT_INC_FOLDER})

include_directories(${SHARED_UTIL_INC_FOLDER})
include_directories(./testtools/iothub_test/inc)

include("${CMAKE_CURRENT_LIST_DIR}/configs/back_compat_functions.cmake")

add_subdirectory(tests)
