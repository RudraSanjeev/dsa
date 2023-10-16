#include <bits/stdc++.h>
using namespace std;

// mergesort by recursion.

void merge(int arr[], int l, int r, int mid)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, r, mid);
}
int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}