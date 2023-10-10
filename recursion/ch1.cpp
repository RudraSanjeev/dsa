#include<bits/stdc++.h>
using namespace std;

void reverseArr(int arr[],int l, int r){
    if(l >= r){
        return;
    }
  
    swap(arr[l], arr[r]);
    reverseArr(arr,l+1, r-1);
}
void reverseArr2(int arr[],int n, int i){
   if(i> n/2){
    return;
   }
   swap(arr[i], arr[n-i -1]);
}

int main()
{
    int arr[] = {1,2,3,4,5};

    reverseArr(arr, 0, 4);
    reverseArr2(arr, 5, 0);
    for(int x : arr){
        cout<<x<<" ";
    }


    return 0;
}