#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, vector<int> &heights)
{
    if (i == n - 1)
        return 0;
    int left = f(i + 1, n, heights) + abs(heights[i] - heights[i + 1]);
    int right = INT_MAX;
    if (i < n - 2)
    {
        right = f(i + 2, n, heights) + abs(heights[i] - heights[i + 2]);
    }
    return min(left, right);
}

int f1(int i, vector<int> &heights)
{
    if (i == 0)
        return 0;
    int left = f1(i - 1, heights) + abs(heights[i] - heights[i - 1]);
    int right = INT_MAX;
    if (i > 1)
    {
        int right = f1(i - 2, heights) + abs(heights[i] - heights[i - 2]);
    }
    return min(left, right);
}

int main()
{
    vector<int> heights = {10, 20, 30, 10};
    int n = heights.size() - 1;
    // cout << f(0, n, heights);
    cout << f1(n, heights);
    cout << endl;
    return 0;
}