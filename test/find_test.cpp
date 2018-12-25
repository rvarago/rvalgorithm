#include <gtest/gtest.h>

extern "C" {
#include "rvalgorithm/end.h"
#include "rvalgorithm/find.h"
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

TEST(rvalgorithm, find_if_n)
{

	const struct person_t person_coll[] = {{"P1", 10}, {"P2", 20}, {"P3", 30}, {"P4", 40}};
	const void *person_p2_found = rv_find_if_n(person_coll, sizeof(struct person_t), 4, id_equals_20);
	EXPECT_STREQ("P2", ((struct person_t*) person_p2_found)->name);
	const void *person_p5_not_found = rv_find_if_n(person_coll, sizeof(struct person_t), 4, id_equals_50);
	EXPECT_EQ(rv_end(person_coll, sizeof(struct person_t), 4), person_p5_not_found);
}