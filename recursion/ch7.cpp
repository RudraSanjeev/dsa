#include <bits/stdc++.h>
using namespace std;
// T(C) = 2^t * k { t is bcoz we are not checking only n times but also sometimes i is not increases or sometimes it increases so let say it is t }
// k --> is for inserting a value k times inside a ds to reach target.
// S(C) = k *x {hypothetical bcoz it depends no of combination generated. here x is no of combination generated}
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