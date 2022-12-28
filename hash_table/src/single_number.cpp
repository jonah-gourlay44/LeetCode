#include <gtest/gtest.h>
#include <unordered_set>

using namespace std;

int singleNumber(vector<int>& nums)
{
    unordered_set<int>* set = new unordered_set<int>();
    for (int num : nums)
        set->insert(num);
    
    for (int num : nums) {
        if (set->count(num) == 1) {
            delete set;
            return num;
        }
    }
    delete set;
    return nums[0];
}

TEST(testSingleNumber, test1)
{
    vector<int> arr = {2,2,1};

    ASSERT_EQ(singleNumber(arr), 1);
}

TEST(testSingleNumber, test2)
{
    vector<int> arr = {4,1,2,1,2};

    ASSERT_EQ(singleNumber(arr), 4);
}

TEST(testSingleNumber, test3)
{
    vector<int> arr = {1};

    ASSERT_EQ(singleNumber(arr), 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}