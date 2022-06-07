/*
    Time complexity: [Best case & Avarage case : O(n*logn)],[Worst case: O(n^2)]
    Space complexity: O(1)
    stable and in palce algo
    More efficient when randomized pivot used
    Recurrence relation: T(n) = 2T(n/2) + θ(n)
*/
/*
    Time taken by QuickSort, in general, can be written as following.

     T(n) = T(k) + T(n-k-1) + \theta (n)

The first two terms are for two recursive calls, the last term is for the partition process. k is the number of elements which are smaller than pivot.
The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases.

Worst Case:
The worst case occurs when the partition process always picks greatest or smallest element as pivot. If we consider above partition strategy where last element is always picked as pivot, the worst case would occur when the array is already sorted in increasing or decreasing order. Following is recurrence for worst case.

     T(n) = T(0) + T(n-1) + \theta (n)which is equivalent to  T(n) = T(n-1) + \theta (n)

The solution of above recurrence is   (n2).

Best Case:
The best case occurs when the partition process always picks the middle element as pivot. Following is recurrence for best case.

     T(n) = 2T(n/2) + \theta (n)
*/

#include <bits/stdc++.h>
using namespace std;

// Higher Element is taken as pivot
int partition(int low, int high, vector<int> &v)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(int low, int high, vector<int> &v)
{
    if (low < high)
    {
        int p = partition(low, high, v);
        quickSort(low, p - 1, v);
        quickSort(p + 1, high, v);
    }
}

/*-----------------------------------------------------*/

// Lower element is taken pivot
int partition2(int low, int high, vector<int> &v)
{
    int pivot = v[low];
    int i = low, j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (v[i] <= pivot);
        do
        {
            j--;
        } while (v[j] > pivot);
        if (i < j)
            swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}

void quickSort2(int low, int high, vector<int> &v)
{
    if (low < high)
    {
        int p = partition(low, high, v);
        quickSort(low, p, v);
        quickSort(p + 1, high, v);
    }
}

/*-----------------------------------------------------*/
// Randomized algo
int randomized_partition(int low, int high, vector<int> &v)
{
    int n = rand();
    int pivot = low + n % (high - low + 1);
    swap(v[high], v[pivot]);
    return partition2(low, high, v);
}
void quickSort3(int low, int high, vector<int> &v)
{
    if (low < high)
    {
        int p = randomized_partition(low, high, v);
        quickSort(low, p, v);
        quickSort(p + 1, high, v);
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

    quickSort3(0, n - 1, arr);
    for (int i : arr)
        cout << i << " ";
}