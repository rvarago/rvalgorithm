#include <gtest/gtest.h>

extern "C" {
#include "rvalgorithm/rvalgorithm.h"
}

TEST(rvalgorithm, end) {
	const int ints[] = {1, 2, 3, 4};
	EXPECT_EQ(3, *((const int*) rv_end(ints, sizeof(int), 2)));
	EXPECT_EQ(ints + 4, rv_end(ints, sizeof(int), 4));

	const char chars[] = {};
	EXPECT_EQ(chars + 1, rv_end(chars, sizeof(char), 1));
}

struct person_t {
	const char name[3];
	const int id;
};

int
id_equals_20(const void *person)
{
	return ((const struct person_t*) person)->id == 20;
}

int
id_equals_50(const void *person)
{
	return ((const struct person_t*) person)->id == 50;
}

TEST(rvalgorithm, find)
{

	const struct person_t person_coll[] = {{"P1", 10}, {"P2", 20}, {"P3", 30}, {"P4", 40}};
	const void *person_p2_found = rv_find_n(person_coll, sizeof(struct person_t), 4, id_equals_20);
	EXPECT_STREQ("P2", ((struct person_t*) person_p2_found)->name);
	const void *person_p5_not_found = rv_find_n(person_coll, sizeof(struct person_t), 4, id_equals_50);
	EXPECT_EQ(rv_end(person_coll, sizeof(struct person_t), 4), person_p5_not_found);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
