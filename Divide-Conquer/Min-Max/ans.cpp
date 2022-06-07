#include <bits/stdc++.h>
using namespace std;

void MinMax(int low, int high, int &max, int &min, vector<int> &v)
{
    if (low == high)
    {
        if (min > v[low])
            min = v[low];
        if (max < v[high])
            max = v[high];
        return;
    }
    if (low == high - 1)
    {
        if (v[low] < v[high])
        {
            if (min > v[low])
                min = v[low];
            else if (max < v[high])
                max = v[high];
        }
        else if (v[low] > v[high])
        {
            if (max < v[low])
                max = v[low];
            else if (min > v[high])
                min = v[high];
        }
        return;
    }
    int mid = (low + high) / 2;
    MinMax(low, mid, max, min, v);
    MinMax(mid + 1, high, max, min, v);
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
    int min = INT_MAX, max = INT_MIN;
    MinMax(0, n - 1, max, min, arr);

    cout << "Minmum element in array: " << min << " "
         << "\nMaximum element in array: " << max;
}