# CMakeLists.txt for ringbuf in CUteLib
file(GLOB ALL_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
add_library(ringbuf STATIC ${ALL_SRCS})
set_target_properties(ringbuf PROPERTIES LINKER_LANGUAGE C)
target_include_directories(ringbuf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (BUILD_TESTING)
    add_executable(test_ringbuf_isempty ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_isempty.c)
    target_link_libraries(test_ringbuf_isempty ringbuf)

    add_executable(test_ringbuf_isfull ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_isfull.c)
    target_link_libraries(test_ringbuf_isfull ringbuf)

    add_executable(test_ringbuf_increasehead ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_increasehead.c)
    target_link_libraries(test_ringbuf_increasehead ringbuf)

    add_executable(test_ringbuf_increasetail ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_increasetail.c)
    target_link_libraries(test_ringbuf_increasetail ringbuf)

    add_executable(test_ringbuf_increaseheadmore ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_increaseheadmore.c)
    target_link_libraries(test_ringbuf_increaseheadmore ringbuf)

    add_executable(test_ringbuf_increasetailmore ${CMAKE_CURRENT_SOURCE_DIR}/testringbuf/test_increasetailmore.c)
    target_link_libraries(test_ringbuf_increasetailmore ringbuf)

    add_test(NAME test_ringbuf_isempty_10_1
            COMMAND test_ringbuf_isempty 10 1)
        
    add_test(NAME test_ringbuf_isempty_27_5
            COMMAND test_ringbuf_isempty 27 5)

    add_test(NAME test_ringbuf_isfull_10_1
            COMMAND test_ringbuf_isfull 10 1)

    add_test(NAME test_ringbuf_isfull_27_5
            COMMAND test_ringbuf_isfull 27 5)

    add_test(NAME test_ringbuf_increasehead_10_1
            COMMAND test_ringbuf_increasehead 10 1)

    add_test(NAME test_ringbuf_increasehead_27_5
            COMMAND test_ringbuf_increasehead 27 5)

    add_test(NAME test_ringbuf_increasetail_10_1
            COMMAND test_ringbuf_increasetail 10 1)

    add_test(NAME test_ringbuf_increasetail_27_5
            COMMAND test_ringbuf_increasetail 27 5)

    add_test(NAME test_ringbuf_increaseheadmore_10_1
            COMMAND test_ringbuf_increaseheadmore 10 1)

    add_test(NAME test_ringbuf_increaseheadmore_27_5
            COMMAND test_ringbuf_increaseheadmore 27 5)

    add_test(NAME test_ringbuf_increasetailmore_10_1
            COMMAND test_ringbuf_increasetailmore 10 1)

    add_test(NAME test_ringbuf_increasetailmore_27_5
            COMMAND test_ringbuf_increasetailmore 27 5)

endif()
