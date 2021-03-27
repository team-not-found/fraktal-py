file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)

add_library(fraktal STATIC
            ${SRCS}
            ${HDRS}
            )
set_target_properties(fraktal PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
target_include_directories(fraktal
                         PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
                         )