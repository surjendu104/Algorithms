//TC : O(n^3)

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int a[MAX][MAX], cost[MAX][MAX];
//return minimum of two number
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd_all_paths(int cost[][MAX], int a[][MAX], int n)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = cost[i][j];


    /*Loop for calculate minimum diatance from a vertex to another*/
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}


//utility function to print the rasult
void Print_result(int cost[][MAX], int a[][MAX], int n)
{
    int i, j;
    printf("\n****The adjacency matrix of the given graph*****\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (cost[i][j] == 999)
                printf("\tinf");
            else
                printf("\t%d", cost[i][j]);
        printf("\n");
    }
    printf("\n ................................................\n ");
    printf("\n*****All the shortest paths obtained is******\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (a[i][j] == 999)
                printf("\tinf");
            else
                printf("\t %d", a[i][j]);
        printf("\n");
    }
    printf("\n ...............................................\n ");
}

int main()
{
    int i, j, n;
    printf("\nEnter the number of vertices:: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix\n");
    printf("(Enter 999 if there is no path)\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    floyd_all_paths(cost, a, n);

    Print_result(cost, a, n);
    return 0;
}


// Tc :O(n^3)