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
