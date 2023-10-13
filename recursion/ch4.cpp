#include <bits/stdc++.h>
using namespace std;

// please dry run all these code and also make recursion tree for all.

// print all the subsequence in order manner
// T(C) = 2^N *N
// S(C) = O(N)
void printAllSubsequences(int ind, vector<int> &ds, int arr[], int n)
{
    if (ind == n)
    {
        for (int x : ds)
        {
            cout << x << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}" << endl;
        }
        cout << endl;
        return;
    }

    // take condition

    ds.push_back(arr[ind]);
    printAllSubsequences(ind + 1, ds, arr, n);
    ds.pop_back();

    // not take condition
    printAllSubsequences(ind + 1, ds, arr, n);
}

// print all the subsequence whose sum = k
void printAllSubsequencesSumK(int ind, vector<int> &ds, int arr[], int n, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (int x : ds)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // take condition
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printAllSubsequencesSumK(ind + 1, ds, arr, n, sum, k);
    ds.pop_back();
    sum -= arr[ind];

    // not take condition
    printAllSubsequencesSumK(ind + 1, ds, arr, n, sum, k);
}

// Print only one subsequence whose sum is equal to k
// 1st method - create a global var as flag = false and if make it true when one time for loop executed and add it inside if block to execute only when if flag is false
// 2nd method - ***(imp) - stop further recursion call if we got a ans
bool printOnlyOneSubSumK(int ind, vector<int> &ds, int arr[], int n, int sum, int k)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (int x : ds)
            {
                cout << x << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }

    // take condition
    ds.push_back(arr[ind]);
    sum += arr[ind];
    if (printOnlyOneSubSumK(ind + 1, ds, arr, n, sum, k) == true)
    {
        return true;
    };
    ds.pop_back();
    sum -= arr[ind];

    // not take condition
    if (printOnlyOneSubSumK(ind + 1, ds, arr, n, sum, k) == true)
    {
        return true;
    }
    return false;
}

// just give me the count
// dry run this code as f(ind, s)
// ref - tut 7 youtube
int printOnlyCountOfSub(int ind, int arr[], int n, int sum, int k)
{

    if (ind == n)
    {
        if (sum == k)
            return 1;
        else
            return 0;
    }

    // take condition
    sum += arr[ind];
    int left = printOnlyCountOfSub(ind + 1, arr, n, sum, k);
    sum -= arr[ind];

    // not take condition
    int right = printOnlyCountOfSub(ind + 1, arr, n, sum, k);
    return left + right;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int ind = 0;
    int sum = 0;
    int k = 2;
    vector<int> ds;
    // printAllSubsequences(0,ds , arr, n);
    // printAllSubsequencesSumK(0, ds, arr, n, 0, k);
    // printOnlyOneSubSumK(0, ds, arr, n, 0, k);
    // printOnlyCountOfSub(0, ds, arr, n, 0, k);
    cout << printOnlyCountOfSub(0, arr, n, 0, k);
    cout << endl;
    return 0;
}