#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findNumber(int n, int *arr, int);
int findPivot(int, int, int *arr, int);
int binarySearch(int beg, int end, int *arr, int key, int dir);

int main()
{
    int t, n, key;
    cin >> t;
    int *arr;
    while (t--)
    {
        cin >> n;
        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> key;
        cout << findNumber(n, arr, key) << endl;
    }
    return 0;
}

int findNumber(int n, int *arr, int key)
{
    // Find pivot element in bitonic array
    int pivot = findPivot(0, n - 1, arr, n - 1);
    // Check if array is bitonic or not
    if (pivot != -1)
    {
        // check if number is present at pivot location and return position
        if (arr[pivot] == key)
        {
            return pivot;
        }
        // Apply binarysearch in left part of pivoted array. This part is sorted in ascending order
        int leftSearch = binarySearch(0, pivot - 1, arr, key, 1);
        // Apply binarysearch in right part of pivoted array. This part is sorted in descending order
        int rightSearch = binarySearch(pivot + 1, n - 1, arr, key, 0);
        // If number is present in left part then return result of left binarysearch else return right binarysearch
        return (leftSearch != -1) ? leftSearch : rightSearch;
    }
    // If there is no pivot element present then apply binarysearch in ascending order on whole array
    return binarySearch(0, n - 1, arr, key, 1);
}

int findPivot(int beg, int end, int *arr, int n)
{
    // return -1 if pivot is not found and search reaches end of array
    if (end - beg < 0)
    {
        return -1;
    }
    // calculate mid of subarray
    int m = beg + (end - beg) / 2;

    // check if mid element satisfies pivot element condition and returns pivot element
    if ((m + 1) <= n && (m - 1) >= 0 && arr[m] > arr[m + 1] && arr[m - 1] < arr[m])
    {
        return m;
    }
    // check if pivot element lies in left subarray
    else if (arr[beg] > arr[m])
    {
        return findPivot(beg, m - 1, arr, n);
    }
    // check if pivot element lies in rigt subarray
    else
    {
        return findPivot(m + 1, end, arr, n);
    }
}

int binarySearch(int beg, int end, int *arr, int key, int dir)
{
    // return -1 if element is not found and search reaches end of array
    if (end < beg)
    {
        return -1;
    }
    // calculate mid of subarray
    int m = beg + (end - beg) / 2;
    //  check if mid element is required number and returns element position
    if (key == arr[m])
    {
        return m;
    }
    // If binarysearch is applied on subarray sorted in ascending order
    if (dir)
    {
        // If number to be searched is smaller than mid element then search in left subarray else in right subarray
        if (arr[m] > key)
        {
            return binarySearch(beg, m - 1, arr, key, dir);
        }
        else
        {
            return binarySearch(m + 1, end, arr, key, dir);
        }
    }
    // If binarysearch is applied on subarray sorted in descending order
    else
    {
        // If number to be searched is smaller than mid element then search in right subarray else in right subarray
        if (arr[m] > key)
        {
            return binarySearch(m + 1, end, arr, key, dir);
        }
        else
        {
            return binarySearch(beg, m - 1, arr, key, dir);
        }
    }
}