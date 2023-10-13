#include<bits/stdc++.h>
using namespace std;

// to find fibbonacci series recursive method

int findRec(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return findRec(n-1) + findRec(n-2);
}

// to find sum of series of up n
int findFibbSum(int n){
    if(n ==0 || n== 1){
        return n;
    }
    return findRec(n) + findFibbSum(n-1);
}

int main()
{
    int n = 3;
    // findRec(n);
    // int sum =findFibbSum(n);
    // cout<<sum;
    // cout<<endl;
    cout<< (5-3-2);
    
    return 0;
}