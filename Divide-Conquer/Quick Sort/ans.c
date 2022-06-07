// Quick sort

#include <stdio.h>

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int *a, int low, int high)
{

    // select the rightmost element as pivot
    int pivot = a[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the a
    // compare them with the pivot
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&a[i], &a[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&a[i + 1], &a[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int *a, int low, int high)
{
    if (low < high)
    {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pos = partition(a, low, high);

        // recursive call on the left of pivot
        quickSort(a, low, pos - 1);

        // recursive call on the right of pivot
        quickSort(a, pos + 1, high);
    }
}

// function to print a elements
void printArray(int *a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

// main function
int main()
{
    int data[] = {5 ,4,3,2,1};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted array\n");
    printArray(data, n);

    // perform quicksort on data
    quickSort(data, 0, n - 1);

    printf("Sorted array : \n");
    printArray(data, n);
}