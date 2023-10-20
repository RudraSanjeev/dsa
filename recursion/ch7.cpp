#include <bits/stdc++.h>
using namespace std;

void combinationSum(int i, int target, vector<int> &ds, int arr[], int n, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(ds);
        return;
    }
    if (i == n || target < 0)
    {
        return;
    }
    ds.push_back(arr[i]);
    combinationSum(i, target - arr[i], ds, arr, n, res);
    ds.pop_back();
    combinationSum(i + 1, target, ds, arr, n, res);
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    int target = 7;
    vector<int> ds;
    vector<vector<int>> res;
    int n = sizeof(arr) / sizeof(arr[0]);
    combinationSum(0, target, ds, arr, n, res);

    for (const vector<int> &combination : res)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}