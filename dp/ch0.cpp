#include <bits/stdc++.h>
using namespace std;

// fibbonacci series -- Memoization
// T(C) = O(N) - Bcoz fetching data from dp is in constant time
// S(C) = O(N + M) ; N- call stack, M - size of dp array. M = N+1;
int fibb(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibb(n - 1, dp) + fibb(n - 2, dp);
}

// fibbonacci series -- Tabulation
// T(C) = O(N)
// S(C) = O(N + 1) - dp
int fibb2(int n, vector<int> &dp)
{
    // base case
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//  fibbonacci series - Best way --  without using an array
// T(C) = O(N)
// S(C) = O(1)
int fibb3(int n)
{
    if (n <= 1)
        return n;

    // base case
    int prev = 1;
    int prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1, -1);
    // cout << fibb(n, dp);
    // cout << fibb2(n, dp);
    cout << fibb3(n);

    cout << endl;

    return 0;
}