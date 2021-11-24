#####################
#        Uri        #
# © 2021 Callum Ali #
#####################
#   DON'T MODIFY!   #
#####################

cmake_minimum_required(VERSION 3.8)

set(Sources
    src/UriTests.cpp
)

add_executable(UriTests ${Sources})

set_target_properties(UriTests PROPERTIES
    FOLDER Tests
)

target_link_libraries(UriTests PUBLIC
    gtest_main
    Uri
)

add_test(
    NAME UriTests
    COMMAND UriTests
)