# CMakeLists.txt for linkedlist in CUteLib
file(GLOB ALL_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_library(linkedlist STATIC ${ALL_SRCS})
set_target_properties(linkedlist PROPERTIES LINKER_LANGUAGE C)
target_include_directories(linkedlist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_TESTING)

endif()