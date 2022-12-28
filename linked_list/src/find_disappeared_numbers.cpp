#include <vector>
#include <iostream>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    int length = nums.size();
    vector<int> out;

    int i = 0;
    while(i < length)
    {
        if (nums[i] != i+1 && nums[nums[i]-1] != nums[i])
            swap(nums[i], nums[nums[i]-1]);
        else
            i++;
    }

    for (int i = 0; i < length; ++i)
    {
        if (nums[i] != i+1)
            out.push_back(i+1);
    }

    return out;
}

int main(void)
{
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> out = findDisappearedNumbers(nums);

    for (int i : out)
        printf("%i ", i);
    printf("\n");
}