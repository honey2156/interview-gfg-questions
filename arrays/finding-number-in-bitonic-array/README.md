# Finding number in a bitonic array
An array is called Bitonic if it is comprises of an increasing sequence of integers followed immediately by a decreasing sequence of integers.
Given a bitonic array A of N distinct integers. Find a element X in it.

Input:
First line will consist  a number T, the number of test cases. First line of each test case will consist of positive integer N. Next line contains array elements and third line contains X.

Output:
Print the index where element found. If element not found, print "-1" (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
-107 <= Ai <= 107

Example:
Input:
1
5
1 2 7 4 3
2
Output:
1

Explanation:
Testcase 1: 2 is found at index 1 in the given array.

Geeksforgeeks link = https://practice.geeksforgeeks.org/problems/finding-number/0

Note :- This approach works only when elements in array are distinct. Will not work with duplicates.