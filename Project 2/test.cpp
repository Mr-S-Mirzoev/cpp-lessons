#include "stf.h"
#include "hash_table.h"

#include <iostream>
#include <random>

using size_type = std::mt19937::result_type;

TEST_MAIN_BEGIN()
{
UNIT_TEST_BEGIN(HashTable, simple)
{
    HashTable <size_type, double> hashtable;

    // Initialize rnd generators
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<size_type> dist_sample(300, 600);
    std::uniform_int_distribution<size_type> dist_op(0, 2);
    std::default_random_engine eng;
    std::uniform_real_distribution<double> unif(-0.5, 0.5);
    size_type sample_sz{dist_sample(rng)};

    for (size_type i = 0; i < sample_sz; ++i)
    {
        auto key = dist_sample(rng);
        if (dist_op(rng) % 3 == 0)
        {
            ASSERT_NO_THROW(hashtable.remove(key));
            ASSERT_THROW_TYPE(hashtable.get(key), std::runtime_error);
        }
        else
        {
            double val {unif(eng)};
            ASSERT_NO_THROW(hashtable.add(key, val));

            ASSERT_NO_THROW(hashtable.get(key));
            ASSERT_EQ(val, hashtable.get(key));
        }
    }
}
UNIT_TEST_END(HashTable, simple)
}
TEST_MAIN_END()
