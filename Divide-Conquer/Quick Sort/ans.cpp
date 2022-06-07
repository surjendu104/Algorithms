

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