#include <bits/stdc++.h>
using namespace std;

// subset sum - given arr, and n
// problem link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1
void subsetSum(int i, vector<int> arr, vector<int> &ds, int n, int sum)
{
    if (i >= n)
    {
        ds.push_back(sum);
        return;
    }
    sum += arr[i];
    subsetSum(i + 1, arr, ds, n, sum);
    sum -= arr[i];
    subsetSum(i + 1, arr, ds, n, sum);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    subsetSum(0, arr, ds, 3, 0);

    // print
    for (auto x : ds)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}