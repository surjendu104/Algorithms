#include <stdio.h>

// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int *arr, int start, int end, int x)
{
    while (start <= end)
    {
        int m = start + (end - start) / 2; /*This is to avoid Overflow when start and end all
         are nearly equal to INT_MAX*/

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            start = m + 1;

        // If x is smaller, ignore right half
        else
            end = m - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

/*Recursive Binary Search*/
int recursiveBinarySearch(int *a, int start, int end, int x)
{
    if (start <= end)
    {

        int mid = start + (end - start) / 2;
        if (a[mid] == x)
            return mid;
        else if (a[mid] < x)
            return recursiveBinarySearch(a, mid + 1, end, x);
        else
        {
            return recursiveBinarySearch(a, start, mid - 1, x);
        }
    }
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result1 = binarySearch(arr, 0, n - 1, x);
    (result1 == -1) ? printf("Element is not present in array\n")
                   : printf("Element is present(0 indexed array) at index %d\n", result1);
    int result2 = recursiveBinarySearch(arr, 0, n - 1, x);
    (result2 == -1) ? printf("Element is not present in array\n")
                    : printf("Element is present(0 indexed array) at index %d\n", result2);
    return 0;
}
