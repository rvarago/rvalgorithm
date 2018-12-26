#include <gtest/gtest.h>

extern "C" {
#include "rvalgorithm/foreach.h"
}

static int total = 0;

void
sum(const void *el)
{
    total += *((const int*) el);
}

TEST(foreachN, sumInts)
{
	const int ints[] = {1, 2, 3, 4};
    rv_foreach_n(ints, sizeof(int), 4, sum);
    EXPECT_EQ(10, total);
}