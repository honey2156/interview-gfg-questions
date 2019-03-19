#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define n 3

void rotateImageBy90(int img[n][n]);
void displayImage(int img[n][n]);

int main(){
    int img[n][n] = {
        {1, 2, 3}, 
        {4, 5, 6},
        {7, 8, 9}
    };
    displayImage(img);
    rotateImageBy90(img);
    displayImage(img);

    return 0;
}

void rotateImageBy90(int img[n][n]){
    // Transpose of image
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i < j){
                swap(img[i][j], img[j][i]);
            }
        }
    }

    // shift columns
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            swap(img[i][j], img[i][n-j-1]);
        }
    }
}

void displayImage(int img[n][n]){
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}