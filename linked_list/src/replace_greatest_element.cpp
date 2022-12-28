#include <vector>
#include <iostream>

using namespace std;

int findLargestElement(const vector<int>& arr, int& largest, int idx)
{
    int ind = arr.size()-1;
    for (int i = arr.size()-1; i > idx; --i)
    {
        ind = arr[i] > largest ? i : ind;
        largest = arr[i] > largest ? arr[i] : largest;
    }
    
    return ind;
}

vector<int> replaceElements(vector<int>& arr)
{
    if (arr.size() == 0)
        return arr;

    int largest = arr[arr.size()-1];
    int idx = findLargestElement(arr, largest, 0);

    for (int i = 0; i < arr.size()-1; ++i)
    {
        if (i == idx)
        {
            largest = arr[arr.size()-1];
            idx = findLargestElement(arr, largest, i);
        }
        arr[i] = largest;
    }
    arr[arr.size()-1] = -1;

    return arr;
}

int main(void)
{
    vector<int> arr = {17,18,5,4,6,1};

    arr = replaceElements(arr);

    for (int i : arr)
        printf("%i ", i);
    printf("\n");
}