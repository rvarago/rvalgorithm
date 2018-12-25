#include <gtest/gtest.h>

extern "C" {
#include "rvalgorithm/end.h"
}

TEST(rvalgorithm, end) {
	const int ints[] = {1, 2, 3, 4};
	EXPECT_EQ(3, *((const int*) rv_end(ints, sizeof(int), 2)));
	EXPECT_EQ(ints + 4, rv_end(ints, sizeof(int), 4));

	const char chars[] = {};
	EXPECT_EQ(chars + 1, rv_end(chars, sizeof(char), 1));
}