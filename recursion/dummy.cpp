#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int r, int mid)
{
    int n1 = mid - l;
    int n2 = r - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
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
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid - 1);
    mergeSort(arr, mid, r);

    merge(arr, l, r, mid);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 7, 6};
    int n = 6;
    mergeSort(arr, 0, n);

    return 0;
}