#include <vector>
#include <iostream>

using namespace std;

namespace my
{
void swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
}

void heapify(vector<int>& arr, int idx, int len)
{
    int root = idx;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;

    if (left < len && arr[left] > arr[root])
        root = left;
    if (right < len && arr[right] > arr[root])
        root = right;
    if (root != idx)
    {
        my::swap(arr[idx], arr[root]);
        heapify(arr, root, len);
    }
}

void heapSort(vector<int>& arr)
{
    if (arr.size() <= 1)
        return;

    for (int i = arr.size()/2 - 1; i >= 0; --i)
        heapify(arr, i, arr.size());

    for(int i = arr.size()-1; i >= 0; --i)
    {
        my::swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}

bool find(vector<int> arr, int num)
{
    if (arr.size() == 0)
        return false;

    int mid = arr.size() / 2;

    if (arr.size() == 1)
        if (arr[0] == num)
            return true;
        else
            return false;

    if (num < arr[mid])
        return find(vector<int>(arr.begin(), arr.begin()+mid), num);
    else if (num > arr[mid])
        return find(vector<int>(arr.begin()+mid+1, arr.end()), num);
    else
        return true;
}

bool checkIfExist(vector<int>& arr)
{
    if (arr.size() <= 1)
        return false;
    
    heapSort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        vector<int> arr2 = arr;
        arr2.erase(arr2.begin()+i);
        if (find(arr2, arr[i]*2))
            return true;
    }
    
    return false;
}

int main(void)
{
    vector<int> arr = {-2,0,10,-19,4,6,-8, 0};

    for (int i : arr)
        printf("%i ", i);
    printf("\n");

    if (checkIfExist(arr))
        printf("two numbers found\n");
    else
        printf("no such numbers\n");
}