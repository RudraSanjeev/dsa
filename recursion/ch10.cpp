#include <bits/stdc++.h>
using namespace std;

void solve(int i, vector<int> arr, int n, set<vector<int>> &res, vector<int> &ds)
{
    if (i >= n)
    {
        res.insert(ds);
        return;
    }
    ds.push_back(arr[i]);
    solve(i + 1, arr, n, res, ds);
    ds.pop_back();
    solve(i + 1, arr, n, res, ds);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    set<vector<int>> res;
    solve(0, arr, 3, res, ds);
    for (auto x : res)
    {
        for (auto xx : x)
        {
            cout << xx << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}