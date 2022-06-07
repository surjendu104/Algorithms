#include <stdio.h>
#include <stdlib.h>

void MinMax(int low, int high, int *max, int *min, int v[])
{
    int lmax, lmin, rmax, rmin;
    if (low == high)
    {
        *min = v[low];
        *max = v[high];
    }
    else if (low == high - 1)
    {
        if (v[low] < v[high])
        {
            *min = v[low];
            *max = v[high];
        }
        else if (v[low] > v[high])
        {
            *min = v[high];
            *max = v[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        MinMax(low, mid, &lmax, &lmin, v);
        MinMax(mid + 1, high, &rmax, &rmin, v);
        *min = (lmin < rmin) ? lmin : rmin;
        *max = (rmax > lmax) ? rmax : lmax;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);

    printf("Enter the array elements \n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = INT_MAX, max = INT_MIN;
    MinMax(0, n - 1, &max, &min, arr);

    printf("Minmum element in array: %d\nMaximum element in array: %d", min, max);
}