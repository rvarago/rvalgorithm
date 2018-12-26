cmake_minimum_required(VERSION 3.10)

project(rvalgorithm)

add_library(${PROJECT_NAME}
	src/end.c
	src/find.c
	src/foreach.c
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		include
)

target_compile_features(${PROJECT_NAME} PRIVATE c_std_11)

enable_testing()
add_subdirectory(3rdparty/googletest)
add_subdirectory(test)
