add_executable(rvalgorithm_test
	rvalgorithm_test.cpp
)

add_test(tests rvalgorithm_test)

target_link_libraries(rvalgorithm_test
	PRIVATE
		gtest
		rvalgorithm
)
