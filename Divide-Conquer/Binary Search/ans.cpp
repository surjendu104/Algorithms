#include <bits/stdc++.h>
using namespace std;

int iterative_binary_search(int start, int end, vector<int> &arr, int target)
{
    if (start == end)
        return arr[start];
    int pos;
    while (start <= end)
    {
        int mid = (end + start) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            start = mid + 1;
        else if (arr[mid] > target)
            end = mid - 1;
    }
    return -1;
}

int recursive_binary_search(int start, int end, vector<int> &arr, int target)
{
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return recursive_binary_search(mid + 1, end, arr, target);
    else if (arr[mid] > target)
        return recursive_binary_search(start, mid - 1, arr, target);

    return -1;
}

int main()
{
    int n;
    int target;
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
    cout << "Enter the number to find in the array: ";
    cin >> target;

    int ans = iterative_binary_search(0, arr.size() - 1, arr, target);
    (ans == -1) ? cout << "Element is not present in array\n" : cout << "Element is present(0 indexed array) at index"
                                                                     << " " << ans << endl;
}