#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void findSmallestAnd2ndSmallestNumbers(int n, int arr[]);

int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSmallestAnd2ndSmallestNumbers(n, arr);
    return 0;
}

void findSmallestAnd2ndSmallestNumbers(int n, int arr[])
{
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    /* If current element is smaller than smallest element then update smallest and 2nd smallest elements.
     *  If current element is smaller than 2nd smallest element and greater than smallest element then update 2nd smallest element.
     */
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secondSmallest && arr[i] > smallest)
        {
            secondSmallest = arr[i];
        }
    }

    cout << "Smallest = " << smallest << endl;
    cout << "Second Smallest = " << secondSmallest << endl;
}