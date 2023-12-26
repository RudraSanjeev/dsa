#include <bits/stdc++.h>
using namespace std;
// frog jump - code studio

// 1st method -- recursion -- T(C) - O(2^N) , S(C) - O(2^N)
int f(int ind, vector<int> &heights)
{

    // base case
    if (ind == 0)
        return 0;

    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return min(left, right);
}

// 2nd method -- Memoization  -- T(C) - O(N) , S(C) - O(N+ N) - call stack + dp
int f2(int ind, vector<int> &heights, vector<int> &dp)
{

    // base case
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}
// 3rd method -- Tabulation (Bottom up) -- T(C) - O(N) , S(C) - O(N+N)
int f3(int n, vector<int> &heights, vector<int> &dp)
{
    // base case
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {

        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i > 1)
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[n - 1];
}

// 4th method -- Optimized - whenever we see pattern of dp[n-1] , dp[n-2] we can do it using in O(1)
//  -- T(C) - O(N) , S(C) - O(1)
int f4(int n, vector<int> &heights)
{

    // base case
    //    int prev = INT_MAX;
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {

        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// Imp - Now slightly change the question - Now we have to return min energy required with k steps
// i.e. Now we can make jump
// - i+1
// - i+2
// - i+3
// - ...
// - i+K

// 1st method -- recursion -- T(C) - O(2^N) , S(C) - O(2^N)
int fc(int ind, int k, vector<int> &heights)
{

    // base case
    if (ind == 0)
        return 0;
    int minSteps = INT_MAX;
    for (int j = 1; j < k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = fc(ind - j, k, heights) + abs(heights[ind] - heights[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}

// 2nd method -- Memoization
int fc2(int ind, int k, vector<int> &heights, vector<int> &dp)
{
    // base case
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int minSteps = INT_MAX;
    for (int j = 1; j < k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = fc(ind - j, k, heights) + abs(heights[ind] - heights[ind - j]);
            minSteps = min(minSteps, jump);
        }
    }
    return dp[ind] = minSteps;
}

// 3rd method -- Tabulation (Bottom up) -- T(C) - O(N) , S(C) - O(N+N)
int f3(int n, vector<int> &heights, vector<int> &dp, int k)
{

    // base case
    dp[0] = 0;
    int minSteps = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = fc(i - j, k, heights) + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    int n = 4;
    vector<int> heights = {10, 20, 30, 10};
    // vector<int> dp(n + 1, -1);
    vector<int> dp(n, -1);
    // cout << f(n - 1, heights);
    // cout << f2(n - 1, heights, dp);
    // cout << f3(n, heights, dp);
    // cout << f4(n, heights);
    int k = 3;
    cout << fc(n, k, heights);

    cout << endl;
    return 0;
}