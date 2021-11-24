#####################
#        Uri        #
# © 2021 Callum Ali #
#####################
#   DON'T MODIFY!   #
#####################

cmake_minimum_required(VERSION 3.8)

set(Headers
    include/Uri/Uri.hpp
)

set(Sources
    src/Uri.cpp
)

add_library(Uri STATIC ${Sources} ${Headers})
set_target_properties(Uri PROPERTIES
    FOLDER Libraries
)

target_include_directories(Uri PUBLIC include)

add_subdirectory(test)