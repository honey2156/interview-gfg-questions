#include <iostream>

using namespace std;

void sortAlternatePosNegNumbers(int n, int arr[]);
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
        sortAlternatePosNegNumbers(n, arr);
        display(n, arr);
    }
    return 0;
}

void sortAlternatePosNegNumbers(int n, int arr[])
{
    int pivotPosition = -1;
    // Partition array into subarrays of negative and positive numbers
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            pivotPosition++;
            swap(arr[pivotPosition], arr[i]);
        }
    }
    // Starting point of positive subarray
    pivotPosition = pivotPosition + 1;

    int start = 0;
    while (start < pivotPosition && pivotPosition < n && arr[start] < 0)
    {
        swap(arr[start], arr[pivotPosition]);
        start+=2;
        pivotPosition++;
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