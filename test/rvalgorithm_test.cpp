#include <gtest/gtest.h>

extern "C" {
#include "rvalgorithm/rvalgorithm.h"
}

struct person_t
{
	char name[10];
	int id;
};

int
id_equals_20(const void *el)
{
	return ((const struct person_t*) el)->id == 20;
}

TEST(rvalgorithm, end) {
	const int ints[] = {1, 2, 3, 4};
	EXPECT_EQ(3, *((const int*) rv_end(ints, sizeof(int), 2)));
	EXPECT_EQ(ints + 4, rv_end(ints, sizeof(int), 4));

	const char chars[] = {};
	EXPECT_EQ(chars + 1, rv_end(chars, sizeof(char), 1));
}

TEST(rvalgorithm, find)
{
	const struct person_t arr[] = {{"P1", 10}, {"P2", 20}, {"P3", 30}, {"P4", 40}};
	const void *arr_f = rv_find(arr, sizeof(struct person_t), 4, id_equals_20);
	EXPECT_STREQ("P2", ((struct person_t*) arr_f)->name);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
