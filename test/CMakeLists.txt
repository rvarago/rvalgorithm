set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

add_executable(rvalgorithm_test
	rvalgorithm_test.cpp
)

add_test(tests rvalgorithm_test)

find_package(gtest REQUIRED)

target_link_libraries(rvalgorithm_test
	PRIVATE
		gtest::gtest
		rvalgorithm
)
