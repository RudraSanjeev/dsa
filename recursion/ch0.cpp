#include<bits/stdc++.h>
using namespace std;

/*
1. print name 5 times
2. print linearly from 1 to N
3. print from N to 1
4. print linearly from 1 to N(backtracking)
5. print from N to 1

*/

// 1. print name 5 times
void printName(int i, int N){
    if(i == N){
        return;
    }
    printName(i+1, N);
    cout<<("anna")<<endl;
}

// 2. print linearly from 1 to N
void print1ToN(int i, int N){
    if(i > N){
        return;
    }
    cout<<(i)<<endl;
    print1ToN(i+1, N);
}
//  3. print linearly from N to 1
void printNTo1(int i, int N){
    if(i > N){
        return;
    }
    printNTo1(i+1, N);
    cout<<(i)<<endl;
}

// 4. print linearly from 1 to N(backtracking) 
void print1ToNBackTrack(int i, int N){
    if(i <= 0){
        return;
    }
    print1ToNBackTrack(i-1, N);
    cout<<(i)<<endl;
}
// 5. print linearly from N to 1 (backtracking) 
void printNTo1BackTrack(int i, int N){
    if(i > N){
        return;
    }
    printNTo1BackTrack(i+1, N);
    cout<<(i)<<endl;
}

int main()
{
    // printName(0, 3);
    // print1ToN(1, 5);
    // printNTo1(1, 5);
    // print1ToNBackTrack(5, 5);
    printNTo1BackTrack(1, 5);
    return 0;
}