#include <vector>
#include <iostream>

using namespace std;

vector<int> sortArrayByParity(vector<int>& A)
{
    if (A.size() == 0)
        return A;

    int even = 0;
    int length = A.size();
    for (int i : A)
        if (i % 2 == 0)
            even++;
    
    int i = 0;
    int j;
    while (i < even)
    {
        if (A[i] % 2 != 0)
        {
            j = i+1;
            while(A[j] % 2 != 0)
                j++;
            swap(A[i], A[j]);
        }
        i++;
    }

    return A;
}

int main(void)
{
    vector<int> nums = {3,1,2,4};

    sortArrayByParity(nums);

    for (int i : nums)
        printf("%i ", i);
    printf("\n");
}