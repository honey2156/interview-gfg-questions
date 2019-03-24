#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMinimumElement(int n, int arr[]);
int findPivotElementInRotatedArray(int beg, int end, int arr[]);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << findMinimumElement(n, arr) << endl;
    }
    return 0;
}

int findMinimumElement(int n, int arr[])
{
    /**
     * Find pivot element.
     * Pivot element in the rotated sorted array is the element which is the maximum element of array and the element next to it is minimum element.
     */
    int pivot = findPivotElementInRotatedArray(0, n - 1, arr);
    // If pivot element is found then return next element to the pivot element else array is not rotated and return first element
    if (pivot != -1)
    {
        return arr[pivot + 1];
    }
    return arr[0];
}

int findPivotElementInRotatedArray(int beg, int end, int arr[])
{
    if (end < beg)
    {
        return -1;
    }
    if (beg == end)
    {
        return beg;
    }

    int mid = beg + (end - beg) / 2;
    // pivot element is the element for which next element is smaller than the current element
    if (mid > beg && arr[mid] < arr[mid - 1])
    {
        return mid - 1;
    }
    else if (mid < end && arr[mid] > arr[mid + 1])
    {
        return mid;
    }
    else if (arr[mid] > arr[beg])
    {
        return findPivotElementInRotatedArray(mid + 1, end, arr);
    }
    else
    {
        return findPivotElementInRotatedArray(beg, mid - 1, arr);
    }
}