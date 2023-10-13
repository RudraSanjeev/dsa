#include<bits/stdc++.h>
using namespace std;


// 1st method 
void reverseArr(int arr[],int l, int r){
    if(l > r){
        return;
    }
  
    swap(arr[l], arr[r]);
    reverseArr(arr,l+1, r-1);
}

// 2nd method
void reverseArr2(int arr[],int n, int i){
   if(i> n/2){
    return;
   }
   swap(arr[i], arr[n-i -1]);
   reverseArr2(arr, n, i+1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    // reverseArr(arr, 0, n-1);
    reverseArr2(arr, 5, 0);
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;


    return 0;
}