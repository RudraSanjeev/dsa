#include<bits/stdc++.h>
using namespace std;
// to check if string is palindrome or not

bool isPalindrome(int i, int n, string s){
    if(i > n/2){
        return true;
    }
    if(s[i] != s[n-i-1]){
        return false;
    }
    return isPalindrome(i+1, n, s);

}
int main()
{
    string s = "abcdba";
    cout<<isPalindrome(0, s.length(), s);
    cout<<endl;
    
    return 0;
}