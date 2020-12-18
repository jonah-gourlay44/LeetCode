#include <vector>
#include <iostream>

using namespace std;

void moveZeros(vector<int>& nums)
{
    if (nums.size() == 0)
        return;

    int non_zeros = 0;
    for (int i : nums)
        if (i != 0)
            non_zeros++;

    int j;
    for (int i = 0; i < non_zeros; ++i)
    {
        if (nums[i] == 0)
        {
            j = i+1;
            while(nums[j] == 0)
                j++;
            swap(nums[i], nums[j]);
        }
    }
}

int main(void)
{
    vector<int> nums = {0,1,0,3,12};

    moveZeros(nums);

    for (int i : nums)
        printf("%i ", i);
    printf("\n");
}