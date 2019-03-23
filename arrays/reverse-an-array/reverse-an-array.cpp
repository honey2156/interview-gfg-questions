#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverseArrayIter(int n, int arr[]);
void printArray(int n, int arr[]);
void reverseArrayRec(int beg, int end, int arr[]);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Array initial state"<<endl;
    printArray(n, arr);
    reverseArrayIter(n, arr);
    cout<<"Array state after reversing iteratively"<<endl;
    printArray(n, arr);
    reverseArrayRec(0, n-1, arr);
    cout<<"Array state after reversing Recursively"<<endl;
    printArray(n, arr);
    return 0;
}

void reverseArrayIter(int n, int arr[]){
    // start with 2 variables beg and end initialized with starting and end position of array.
    int beg = 0, end = n-1;
    // swap arr[beg] and arr[end] till start and end match
    while(beg < end){
        swap(arr[beg], arr[end]);
        beg++;
        end--;
    }
    return;
}

void reverseArrayRec(int beg, int end, int arr[]){
    if(end < beg){
        return;
    }
    swap(arr[beg], arr[end]);
    beg++;
    end--;
    reverseArrayRec(beg, end, arr);
}

void printArray(int n, int arr[]){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}