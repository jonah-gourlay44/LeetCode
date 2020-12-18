#include <vector>

using namespace std;

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
        swap(arr[idx], arr[root]);
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
        swap(arr[i], arr[0]);
        heapify(arr, 0, i);
    }
}