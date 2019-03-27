#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sortZerosOnesTwos(int n, int arr[]);
void display(int n, int arr[]);

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
        sortZerosOnesTwos(n, arr);
        display(n, arr);
    }
    return 0;
}

void sortZerosOnesTwos(int n, int arr[])
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
        {   // swap only if values of low and mid pointer are different
            if (arr[low] != arr[mid])
            {
                swap(arr[low], arr[mid]);
            }
            low++;
            mid++;
            break;
        }
        case 1:
        {
            mid++;
            break;
        }
        case 2:
        {   // swap only if values of mid and high pointer are different
            if (arr[mid] != arr[high])
            {
                swap(arr[mid], arr[high]);
            }
            high--;
            break;
        }
        }
    }
}

void display(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}