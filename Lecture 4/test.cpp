#include "stf.h"
#include "vector.h"

TEST_MAIN_BEGIN()
{
UNIT_TEST_BEGIN(Vector, vec_utils)
{
    Vector v;
    v.push_back(10);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v.size(), 1);
    EXPECT_THROW_TYPE(v[1], std::runtime_error);
    v.pop_back();
    EXPECT_EQ(v.size(), 0);
    EXPECT_TRUE(v.capacity() > 0);
}
UNIT_TEST_END(Vector, vec_utils)
}
TEST_MAIN_END()