#include <vector>
#include <iostream>

int get_idx(std::vector<int> arr, int num, int start_idx, int end_idx)
{
    int mid = arr.size() / 2;
    
    if (arr.size() == 1)
        return num >= arr[0] ? end_idx + 1 : end_idx;

    if (num < arr[mid])
        return get_idx(std::vector<int>(arr.begin(),arr.begin()+mid), num, start_idx, start_idx+mid-1);
    else
        return get_idx(std::vector<int>(arr.begin()+mid,arr.end()), num, start_idx+mid, end_idx);
    
}

int main(void)
{
    std::vector<int> arr1 {-1, 3, 5, 7, 9, 0, 0, 0, 0};
    std::vector<int> arr2 {-3, 2, 6, 10};

    std::vector<int> arr(arr1.begin(), arr1.begin()+5);

    for (int i : arr)
        printf("%i, ", i);
    printf("\n");
    
    for (int i = 0; i < arr2.size(); ++i)
    {
        int idx = get_idx(arr, arr2[i], 0, 4) + i;
        for (int j = arr1.size()-1; j > idx; --j)
            arr1[j] = arr1[j-1];
        arr1[idx] = arr2[i];
    }

    for (int i : arr1)
        printf("%i, ", i);
    printf("\n");
    
}