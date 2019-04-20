# Maximize Number of 1's 
Given a binary array A of size N and an integer M. Find the maximum number of consecutive 1's produced by flipping at most M 0's.

Input:
The first line contains an integer T denoting the total number of test cases. In each test cases, the first line contains an integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.  Third line consists of an integer m that is maximum number of flips allowed.

Output:
Output the maximum numbers of consecutive 1's.

Constraints:
1 <= T <= 103
1 <= N <= 107
0 <= M <= N
0 <= Ai <= 1

Example:
Input:
1
11
1 0 0 1 1 0 1 0 1 1 1
2

Output:
8

Explanation:
Testcase 1: Maximum subarray is of size 8 which can be made subarray of all 1 after flipping two zeros to 1.

gfg link= https://practice.geeksforgeeks.org/problems/maximize-number-of-1s/0
