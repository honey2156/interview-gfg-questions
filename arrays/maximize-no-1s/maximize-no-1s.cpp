#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void display(int arr[], int begin, int window);
void maximizeOnesByFlippingZeroes(int arr[], int n, int m);

int main(){
    int t, n, m;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        cin>>m;
        maximizeOnesByFlippingZeroes(arr, n, m);
    }
    return 0;
}

void maximizeOnesByFlippingZeroes(int arr[], int n, int m){
    int windowLeft = 0, windowRight = 0, maxWindow = 0, maxWindowBegin = 0, zeroes = 0;

    while(windowRight < n){

        if(zeroes <= m){
            if(arr[windowRight] == 0){
                zeroes++;
            }
            windowRight++;
        }

        if(zeroes >= m){
            while(zeroes > m && windowLeft < windowRight){
                if(arr[windowLeft] == 0){
                    zeroes--;
                }
                windowLeft++;
            }
        }

        if(windowRight - windowLeft > maxWindow && zeroes <= m){
            maxWindow = windowRight - windowLeft;
            maxWindowBegin = windowLeft;
        }
    }

    display(arr, maxWindowBegin, maxWindow);
}

void display(int arr[], int begin, int window){
    /**
     * Uncomment for printing positions of zeroes to be flipped
        for(int i = begin; i < begin + window; i++){
            if(arr[i] == 0){
                cout<<i<<" ";
            }
        }
        cout<<endl;
    **/
    cout<<window<<endl;
}