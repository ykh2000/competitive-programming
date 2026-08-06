cmake_minimum_required(VERSION 3.20)

project(CompetitiveProgramming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find every cpp file recursively
file(GLOB_RECURSE CPP_FILES CONFIGURE_DEPENDS "*.cpp")

foreach(FILE ${CPP_FILES})

    # Relative path from project root
    file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${FILE}")

    # Turn the path into a valid C identifier
    string(MAKE_C_IDENTIFIER "${REL_PATH}" TARGET)

    add_executable("${TARGET}" "${FILE}")

    target_compile_definitions("${TARGET}" PRIVATE LOCAL)

    target_compile_options("${TARGET}" PRIVATE
            -Wall
            -Wextra
            -Wshadow
            -g
    )

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        target_compile_options("${TARGET}" PRIVATE
                -fsanitize=address
                -fsanitize=undefined
        )

        target_link_options("${TARGET}" PRIVATE
                -fsanitize=address
                -fsanitize=undefined
        )
    endif()

endforeach()