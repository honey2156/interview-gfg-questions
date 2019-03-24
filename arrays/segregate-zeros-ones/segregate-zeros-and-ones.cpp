#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void segregateZerosOnes(int n, int arr[]);
void display(int n, int arr[]);

int main(){
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        segregateZerosOnes(n, arr);
        display(n, arr);
    }
    return 0;
}

void segregateZerosOnes(int n, int arr[]){
    int start = 0, end = n-1;
    while(start < end){
        while(arr[start] == 0 && start < end){
            start++;
        }
        while(arr[end] == 1 && start < end){
            end--;
        }
        if(start < end){
            swap(arr[start], arr[end]);
        }
    }
}

void display(int n, int arr[]){
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}