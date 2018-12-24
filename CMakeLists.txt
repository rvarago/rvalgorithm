cmake_minimum_required(VERSION 3.10)

project(rvalgorithm)

add_library(${PROJECT_NAME}
	src/rvalgorithm.c
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		src
)
