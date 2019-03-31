#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findFirstRepeatingElement(int n, int arr[]);

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
        int firstRepeatingElementPosition = findFirstRepeatingElement(n, arr);
        if (firstRepeatingElementPosition != -1)
        {
            cout << "Elemet is " << arr[firstRepeatingElementPosition] << endl;
        }
        else
        {
            cout << "No element repeating in array" << endl;
        }
    }
    return 0;
}

int findFirstRepeatingElement(int n, int arr[])
{
    map<int, bool> m;
    int firstRepeatingElement = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (m.find(arr[i]) != m.end())
        {
            firstRepeatingElement = i;
        }
        else
        {
            m[arr[i]] = true;
        }
    }
    return firstRepeatingElement;
}