#include <bits/stdc++.h>
using namespace std;

// subset sum I

void subsetSum(int i, vector<int> &arr, int n, int sum, vector<int> &ds)
{
    if (i == n)
    {
        ds.push_back(sum);
        return;
    }
    ds.push_back(arr[i]);
    sum += arr[i];

    subsetSum(i + 1, arr, n, sum, ds);
    sum -= arr[i];
    ds.pop_back();
    subsetSum(i + 1, arr, n, sum, ds);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ds;
    int n = arr.size();
    subsetSum(0, arr, n, 0, ds);

    sort(ds.begin(), ds.end());

    for (auto x : ds)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}