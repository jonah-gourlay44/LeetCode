#include <vector>
#include <iostream>

using namespace std;

int thirdMax(vector<int>& nums)
{
    int length = nums.size();

    int largest, smallest;
    largest = smallest = nums[0];
    for (int i = 0; i < length; ++i)
    {
        if (nums[i] < smallest)
            smallest = nums[i];
        if (nums[i] > largest)
            largest = nums[i];
    }

    if (largest - smallest <= 1)
        return largest;
    
    int largest2, largest3;
    largest2 = largest3 = smallest;
    for (int i = 0; i < length; ++i)
    {
        if (nums[i] > largest2 && nums[i] < largest)
        {
            largest3 = largest2;
            largest2 = nums[i];
        }
    }

    if (largest2 == largest3)
        return largest;

    for (int i = 0; i < length; ++i)
    {
        if (nums[i] > largest3 && nums[i] < largest2)
            largest3 = nums[i];
    }

    return largest3;
}

int main(void)
{
    vector<int> input1 = {3,2,1};
    vector<int> input2 = {1,2};
    vector<int> input3 = {-2147483648,1,1};

    printf("third max 1: %i\n", thirdMax(input1));
    printf("third max 2: %i\n", thirdMax(input2));
    printf("third max 3: %i\n", thirdMax(input3));
}