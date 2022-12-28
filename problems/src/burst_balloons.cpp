#include <vector>
#include <gtest/gtest.h>

typedef std::vector<int>::iterator Iter;

void getCosts(const std::vector<int>& nums, int start, int end, Iter cost, int max, int max2, int max3)
{
    for (int i = start; i < end; i++)
    {
        int i_minus_1, i_plus_1;
        i_minus_1 = i - 1 < 0 ? 1 : nums[i-1];
        i_plus_1 = i + 1 >= nums.size() ? 1 : nums[i+1];

        int max_term;
        if (nums[i] == max)
            max_term = max2 * nums[i] * max3;
        else if (nums[i] == max2)
            max_term = max * nums[i] * max3;
        else
            max_term = max * nums[i] * max2;

        *cost = max_term - i_minus_1 * nums[i] * i_plus_1 + nums[i];
        cost++;
    }
}

void getMaxes(const std::vector<int>& nums, int& max, int& max2, int& max3)
{
    for (int num : nums)
    {
        if (num >= max) {
            max3 = max2;
            max2 = max;
            max = num;
        } else if (num >= max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
    }
}

int getArgMinCost(const std::vector<int>& costs)
{
    int min_cost = 1e6;
    int arg_min_cost = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if (costs[i] < min_cost) {
            min_cost = costs[i];
            arg_min_cost = i;
        }
    }

    return arg_min_cost;
}

void pop(std::vector<int>& nums, std::vector<int>& costs, int idx, int& coins)
{
    int i_minus_1, i_plus_1;
    i_minus_1 = idx - 1 < 0 ? 1 : nums[idx - 1];
    i_plus_1 = idx + 1 >= nums.size() ? 1 : nums[idx + 1];

    coins += i_minus_1 * nums[idx] * i_plus_1;
    nums.erase(nums.begin() + idx);
    costs.erase(costs.begin() + idx);
}

void popAllBalloons(std::vector<int>& nums, std::vector<int>& costs, int& coins, int max, int max2, int max3)
{
    if (nums.size() == 0)
        return;

    int idx = getArgMinCost(costs);
    bool max_removed_flag = nums[idx] == max || nums[idx] == max2 || nums[idx] == max3;

    //std::cout << nums[idx] << std::endl;

    pop(nums, costs, idx, coins);

    if (max_removed_flag) {
        getMaxes(nums, max, max2, max3);
        getCosts(nums, 0, nums.size(), costs.begin(), max, max2, max3);
    } else {
        getCosts(nums, idx - 1, idx + 1, costs.begin() + idx - 1, max, max2, max3);
    }

    popAllBalloons(nums, costs, coins, max, max2, max3);
}

int maxCoins(std::vector<int>& nums)
{
    std::vector<int> costs(nums.size());
    int max, max2, max3;
    max = max2 = max3 = 0;

    getMaxes(nums, max, max2, max3);
    getCosts(nums, 0, nums.size(), costs.begin(), max, max2, max3);

    //std::cout << max << " " << max2 << " " << max3 << std::endl;

    /*for (int cost : costs)
        std::cout << cost << " ";
    std::cout << std::endl;*/

    int coins = 0;
    popAllBalloons(nums, costs, coins, max, max2, max3);

    return coins;
}

TEST(test_burst_balloons, test1)
{
    std::vector<int> nums = { 3, 1, 5, 8 };
    ASSERT_EQ(maxCoins(nums), 167);
}

TEST(test_burst_balloons, test2)
{
    std::vector<int> nums = { 1, 5 };
    ASSERT_EQ(maxCoins(nums), 10);
}

TEST(test_burst_balloons, test3)
{
    std::vector<int> nums = { 10, 1, 1, 1, 2, 4, 3, 6 };
    ASSERT_EQ(maxCoins(nums), 502);
}