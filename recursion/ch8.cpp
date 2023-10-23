#include <bits/stdc++.h>
using namespace std;

// combination sum2

// void findCombinationSumII(int i, int target, vector<int> &arr, int n, set<vector<int>> &ans, vector<int> &ds)
// {
//     if (i == n)
//     {
//         if (target == 0)
//         {
//             ans.insert(ds);
//         }
//         return;
//     }
//     for (int j = i; j < n; j++)
//     {
//         if (j > i && arr[j] == arr[j - 1])
//             continue;
//         if (arr[j] > target)
//             break;

//         ds.push_back(arr[j]);
//         findCombinationSumII(j + 1, target - arr[j], arr, n, ans, ds);
//         ds.pop_back();
//     }
// }

void findCombinationSumII(int i, int target, vector<int> &arr, int n, set<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.insert(ds);
        return;
    }

    if (i == n || target < 0)
    {
        return;
    }

    for (int j = i; j < n; j++)
    {
        // Skip duplicates
        if (j > i && arr[j] == arr[j - 1])
        {
            continue;
        }

        ds.push_back(arr[j]);
        findCombinationSumII(j + 1, target - arr[j], arr, n, ans, ds);
        ds.pop_back();
    }
}
void findCombinationSumII2(int i, int target, vector<int> &arr, int n, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    if (i == n || target < 0)
    {
        return;
    }

    for (int j = i; j < n; j++)
    {
        // Skip duplicates
        if (j > i && arr[j] == arr[j - 1])
        {
            continue;
        }
        if (arr[j] > target)
            break;

        ds.push_back(arr[j]);
        findCombinationSumII2(j + 1, target - arr[j], arr, n, ans, ds);
        ds.pop_back();
    }
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    // set<vector<int>> ans;
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinationSumII2(0, target, arr, n, ans, ds);

    vector<vector<int>> final(ans.begin(), ans.end());
    for (auto X : final)
    {
        for (auto xx : X)
        {
            cout << xx << " ";
        }
        cout << endl;
    }

    return 0;
}