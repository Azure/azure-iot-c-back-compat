#Copyright (c) Microsoft. All rights reserved.
#Licensed under the MIT license. See LICENSE file in the project root for full license information.

function(back_compat_add_exe whatIsBuilding folder)

    add_executable(${whatIsBuilding}_exe
        ${${whatIsBuilding}_test_files}
        ${${whatIsBuilding}_cpp_files}
        ${${whatIsBuilding}_h_files}
        ${${whatIsBuilding}_c_files}
        ${logging_files}
    )
    set_target_properties(${whatIsBuilding}_exe
               PROPERTIES
               FOLDER ${folder})

    #target_compile_definitions(${whatIsBuilding}_exe PUBLIC -DUSE_CTEST)
    #target_include_directories(${whatIsBuilding}_exe PUBLIC ${sharedutil_include_directories})

    #this part detects
    #       - the additional libraries that might be needed.
    #     additional libraries are started by ADDITIONAL_LIBS parameter and ended by any other known parameter (or end of variable arguments)
    #   - a valgrind suppression file (VALGRIND_SUPPRESSIONS_FILE) for memcheck
    #     the file name follows immediately after

    # set(PARSING_ADDITIONAL_LIBS OFF)
    # set(PARSING_VALGRIND_SUPPRESSIONS_FILE OFF)
    # set(VALGRIND_SUPPRESSIONS_FILE_EXTRA_PARAMETER)
    # set(ARG_PREFIX "none")
    # foreach(f ${ARGN})
    #     set(skip_to_next FALSE)
    #     if(${f} STREQUAL "ADDITIONAL_LIBS")
    #         SET(PARSING_ADDITIONAL_LIBS ON)
    #         SET(PARSING_VALGRIND_SUPPRESSIONS_FILE OFF)
    #         set(ARG_PREFIX "none")
    #         #also unset all the other states
    #         set(skip_to_next TRUE)
    #     elseif(${f} STREQUAL "VALGRIND_SUPPRESSIONS_FILE")
    #         SET(PARSING_ADDITIONAL_LIBS OFF)
    #         SET(PARSING_VALGRIND_SUPPRESSIONS_FILE ON)
    #         set(skip_to_next TRUE)
    #     endif()

    #     if(NOT skip_to_next)
    #         if(PARSING_ADDITIONAL_LIBS)
    #             if((${f} STREQUAL "debug") OR (${f} STREQUAL "optimized") OR (${f} STREQUAL "general"))
    #                 SET(ARG_PREFIX ${f})
    #             else()
    #                 target_link_libraries_with_arg_prefix(${ARG_PREFIX} ${whatIsBuilding}_exe ${f})
    #                 set(ARG_PREFIX "none")
    #             endif()
    #         elseif(PARSING_VALGRIND_SUPPRESSIONS_FILE)
    #             set(VALGRIND_SUPPRESSIONS_FILE_EXTRA_PARAMETER "--suppressions=${f}")
    #         endif()
    #     endif()

    # endforeach()

    if (WIN32)
        target_include_directories(${whatIsBuilding}_exe PUBLIC ${sharedutil_include_directories})
    else ()
        target_link_libraries(${whatIsBuilding}_exe m)
    endif ()
    add_test(NAME ${whatIsBuilding} COMMAND $<TARGET_FILE:${whatIsBuilding}_exe>)
endfunction()

function(build_back_compat_test_artifacts whatIsBuilding folder)

    #the first argument is what is building
    #the second argument is whether the tests should be build with gballoc #defines or not
    #the following arguments are a list of libraries to link with

    set(logging_files ${XLOGGING_C_FILE} ${LOGGING_C_FILE})

    #setting #defines
    back_compat_add_exe(${whatIsBuilding} ${folder} ${ARGN})

endfunction()
