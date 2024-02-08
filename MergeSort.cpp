//Merge Sort

#include<iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            index++, right++;
        }
    }

    // left not empty
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }

    // right not empty
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }

    index = 0;

    // inserting values in array
    while (start  <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
    
  
}

void divide(int arr[], int start, int end)
{
    if (start == end)
        return;

    int mid = (start + end) / 2;

    // left
    divide(arr, start, mid);
    // right
    divide(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main()
{
    int i, arr[] = {5, 23, 67, 3, 7, 34, 2, 77};

    divide(arr, 0, 7);

    for (i = 0; i < 8; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}
