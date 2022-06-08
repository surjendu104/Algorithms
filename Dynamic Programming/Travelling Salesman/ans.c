#include <stdio.h>
#include <limits.h>

/* A 2d array to store the adjancy matrix
    visited array to keep the track of visited cities
    cost to calculate the minimum cost and n for the number of cities
*/
int graph[100][100], visited[100], cost = 0, n;
int mini(int a, int b)
{
    return (a < b) ? a : b;
}
void takeInput()
{
    printf("\nEnter the number of cities: ");
    scanf("%d", &n);
    printf("\nEnter the adjancency matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = 0;
    }
    printf("\nThe cost matrix is:: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

// To find the next node
int findNextNode(int node)
{
    int m = INT_MAX, min = INT_MAX, minNode;
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] != 0 && (!visited[i]))
        {
            if (graph[node][i] < min)
            {
                min = mini((graph[node][i] + graph[i][0]), min);
                minNode = graph[node][i];
                m = i;
            }
        }
    }
    if (min != INT_MAX)
    {
        cost += minNode;
    }
    return m;
}

void tsp(int node)
{
    int next_node;
    visited[node] = 1;
    printf("%d-->", node + 1);
    next_node = findNextNode(node);

    if (next_node == INT_MAX)
    {
        next_node = 0;
        printf("%d", next_node + 1);
        cost += graph[node][next_node];
        return;
    }
    // calling function for next node
    tsp(next_node);
}

void displayResult()
{
    printf("\n\nThe Minimum Cost: %d", cost);
}

int main()
{
    takeInput();
    printf("\nEnter the starting node: ");
    int start;
    scanf("%d", &start);
    printf("\nThe minimum path is: \n");
    tsp(start);
    displayResult();
    return 0;
}
