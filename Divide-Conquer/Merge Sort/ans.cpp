/*
    Time complexity- O(n*logn)
    Space complexity: O(n)
    stable but not in palce algo
    More space efficient in Linked list than Array
    Recurrence relation: T(n) = 2T(n/2) + θ(n)
*/
#include <bits/stdc++.h>
using namespace std;

void merge(int low, int high, int mid, vector<int> &v)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> a(n1);
    vector<int> b(n2);
    for (int i = 0; i < n1; i++)
        a[i] = v[low + i];
    for (int i = 0; i < n2; i++)
        b[i] = v[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            v[k] = a[i];
            i++;
            k++;
        }
        else
        {
            v[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        v[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        v[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int low, int high, vector<int> &v)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid, v);
        mergeSort(mid + 1, high, v);
        merge(low, high, mid, v);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements of the array: ";
    cin >> n;

    cout << "Enter the array elements \n";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    mergeSort(0, n - 1, arr);

    cout << "Sorted Array" << endl;
    for (int i : arr)
        cout << i << " ";
}