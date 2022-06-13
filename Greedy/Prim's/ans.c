#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 400

int n;


int minKey(int key[], bool mstset[])
{
    int min = INT_MAX, minIdx;
    for (int i = 0; i < n; i++)
    {
        if (mstset[i]==false && key[i] < min)
        {
            min = key[i];
            minIdx = i;
        }
    }
    return minIdx;
}

int printMst(int parent[], int graph[n][n])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int primsMst(int graph[n][n])
{
    int parent[n], key[n];
    bool mstset[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u = minKey(key, mstset);
        mstset[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && mstset[v]==false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMst(parent, graph);
}

int main()
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("\nEnter the adjacency matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    primsMst(graph);
    return 0;
}

/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/