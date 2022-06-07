#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int graph[MAX][MAX], n;

int dist[MAX], visited[MAX];

void takeInput()
{
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    printf("\n\nEnter the adjacency matrix(Enter 0 if there is no direct edge) : \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

int minimum_distance(int dist[], int visited[])
{
    int min = INT_MAX, min_idx;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void print_solution(int dist[])
{

    printf("Vertex no. \tDistance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t%d\n", i, dist[i]);
    }
}

void bellmannFord_imp(int graph[][MAX], int s)
{

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[s] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int x = minimum_distance(dist, visited);

        visited[x] = 1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && graph[x][j] && dist[x] != INT_MAX && dist[x] + graph[x][j] < dist[j])
            {
                dist[j] = dist[x] + graph[x][j];
            }
        }
    }

    int flag = 1;
}

void check_negative_cycle()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (dist[j] != INT_MAX && dist[graph[i][j]] + graph[i][j] < dist[graph[j][i]])
            {
                printf("\nGraph contains negative cycle\n");
                return;
            }
        }
    }
}

int main()
{
    takeInput();
    bellmannFord_imp(graph, 0);
    check_negative_cycle();
    print_solution(dist);
    return 0;
}