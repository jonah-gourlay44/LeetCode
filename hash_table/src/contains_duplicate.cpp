#include <gtest/gtest.h>
#include "hash_set.h"

bool containsDuplicate(vector<int>& nums)
{
    HashSet * set = new HashSet();
    for (int num : nums) {
        if (set->contains(num))
            return true;
        set->add(num);
    }
    delete set;
    return false;
}

TEST(duplicateTest, test1)
{
    vector<int> arr = {1,2,3,1};

    ASSERT_TRUE(containsDuplicate(arr));
}

TEST(duplicateTest, test2)
{
    vector<int> arr = {1,2,3,4};

    ASSERT_FALSE(containsDuplicate(arr));
}

TEST(duplicateTest, test3)
{
    vector<int> arr = {1,1,1,3,3,4,3,2,4,2};

    ASSERT_TRUE(containsDuplicate(arr));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}