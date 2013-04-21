cmake_minimum_required(VERSION 2.8)

project(Shared)

SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(shared)
add_subdirectory(examples/zlibcd)
add_subdirectory(examples/template)

SET_PROPERTY(TARGET Shared		PROPERTY FOLDER "Library")
SET_PROPERTY(TARGET zlibcd		PROPERTY FOLDER "Examples")
SET_PROPERTY(TARGET template	PROPERTY FOLDER "Examples")