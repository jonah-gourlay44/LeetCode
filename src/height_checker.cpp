#include <vector>
#include <iostream>
#include "utils.hpp"

using namespace std;

int heightChecker(vector<int>& heights)
{
    vector<int> diff = heights;

    heapSort(heights);

    int students = 0;
    for (int i = 0; i < diff.size(); ++i)
        if (diff[i] - heights[i] != 0)
            students++;
    
    return students;
}

int main(void)
{
    vector<int> heights1 = {1,1,4,2,1,3};
    vector<int> heights2 = {5,1,2,3,4};
    vector<int> heights3 = {1,2,3,4,5};

    printf("min students 1: %i\n", heightChecker(heights1));
    printf("min students 2: %i\n", heightChecker(heights2));
    printf("min students 3: %i\n", heightChecker(heights3));
}