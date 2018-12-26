add_executable(rvalgorithm_test
	algorithm_test.cpp
	end_test.cpp
	find_test.cpp
	foreach_test.cpp
)

add_test(tests rvalgorithm_test)

target_link_libraries(rvalgorithm_test
	PRIVATE
		gtest
		rvalgorithm
)
