cmake_minimum_required(VERSION 2.8)
project(Database)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/ SUB_SOURCES)

# ($(SUB_SOURCES))

add_library(Database STATIC ${SUB_SOURCES})
