add_test(NAME end2end_test
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/test.sh
            ${CMAKE_CURRENT_SOURCE_DIR}/..
            $<TARGET_FILE:matrix> 30
)