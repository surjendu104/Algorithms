#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void swap2(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

void sort_by_profit(int a[][2], int n)
{
    double profit[n];
    for (int i = 0; i < n; i++)
    {
        profit[i] = ((double)a[i][0] / a[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (profit[minIdx] < profit[j])
            {
                minIdx = j;
            }
        }
        swap2(&profit[minIdx], &profit[i]);
        swap(&a[i][0], &a[minIdx][0]);
        swap(&a[i][1], &a[minIdx][1]);
    }
}

double F_kanpsack(int a[][2], int n, int capacity)
{
    double finalProfit = 0.0;
    printf("\nSelected Items\n\n");
    printf("\nweight\t\tvalue\n");
    for (int i = 0; i < n; i++)
    {

        if (a[i][1] <= capacity)
        {
            printf("\n%d\t\t%d\n", a[i][1], a[i][0]);
            capacity -= a[i][1];
            finalProfit += a[i][0];
        }
        else
        {
            double temp = capacity * ((double)a[i][0] / (double)a[i][1]);
            finalProfit += temp;
            printf("\n%d\t\t%f", capacity, temp);
            break;
        }
        // printf("\n%f ",finalProfit);
    }
    return finalProfit;
}

int main()
{
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int a[n][2];
    printf("\nEnter the data => (Profit,Weight) format\n");
    for (int i = 0; i < n; i++)
    {
        // printf("\nEnter data -%d : ",i);
        scanf("%d", &a[i][0]);
        scanf("%d", &a[i][1]);
    }
    int capacity;
    printf("\nEnter the capacity: ");
    scanf("%d", &capacity);
    sort_by_profit(a, n);
    printf("\nSorted items\n");
    for (int i = 0; i < n; i++)
    {
        printf("(%d,%d)  ", a[i][0], a[i][1]);
    }
    double ans = F_kanpsack(a, n, capacity);
    printf("\nMaximum profit: %f ", ans);
}