#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

cmake_minimum_required(VERSION 2.8.11)

#compileAsC11()
set(theseTestsName iothub_amqp_back_compat)

set(${theseTestsName}_test_files
    ${theseTestsName}.c
)

set(${theseTestsName}_c_files
    ${IOTHUB_REPO_FOLDER}/certs/certs.c
    ../common_test_files/back_compat_test_common.c
)

set(${theseTestsName}_h_files
    ../common_test_files/back_compat_test_common.h
)

if (${use_sample_trusted_cert})
    add_definitions(-DSET_TRUSTED_CERT_IN_SAMPLES)
    include_directories(${IOTHUB_REPO_FOLDER}/certs)
endif()

build_back_compat_test_artifacts(${theseTestsName} "back-compat_tests/iothub_client")

include_directories(../common_test_files)
include_directories(${IOTHUB_TEST_INC_FOLDER})
include_directories(${IOTHUB_SERVICE_CLIENT_INC_FOLDER})

if (TARGET ${theseTestsName}_exe)
    target_link_libraries(${theseTestsName}_exe
            iothub_test
            iothub_client
            iothub_client_amqp_transport
            iothub_service_client
            uamqp
            aziotsharedutil
    )
endif()

if (WIN32)
    if(TARGET ${theseTestsName}_dll)
        target_link_libraries(${theseTestsName}_dll
                iothub_test
                iothub_client
                iothub_client_amqp_transport
                iothub_service_client
                uamqp
                aziotsharedutil
                rpcrt4
        )

        target_link_libraries(${theseTestsName}_dll rpcrt4)
    endif()

   if(TARGET ${theseTestsName}_exe)
       target_link_libraries(${theseTestsName}_exe rpcrt4)
   endif()
else ()
    if (UNIX) #LINUX OR APPLE
        find_package(PkgConfig REQUIRED)
        pkg_search_module(UUID REQUIRED uuid)
        link_directories(${UUID_LIBRARY_DIRS})
    endif ()

    if (APPLE)
        target_link_libraries(${theseTestsName}_exe -L${UUID_LIBRARY_DIRS} pthread ${UUID_LIBRARIES})
    elseif (LINUX)
        target_link_libraries(${theseTestsName}_exe pthread ${UUID_LIBRARIES})
    endif()
endif()
