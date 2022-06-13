#include <stdio.h>
#include <stdlib.h>


#define MAX 100
int n, x = 1; //number of vertices and starting node = 1
int min, mincost = 0, graph[MAX][MAX], parent[MAX];
// int find(int);
int i, j, k, a, b, u, v; //declaired general variables as global

//function to check node is included in set or not ,if not then include it 
int set_union(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

//checking node is parent node of the set or not
int find_node(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
void takeInput(){
    printf("\nEnter the no. of vertices:");
    scanf("%d", &n);
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }
    }

    printf("\n\nEntered adjacency matrix is\n\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(graph[i][j]==999){
                printf("INF\t");
            }else{

                printf("%d\t",graph[i][j]);
            }
        }
        printf("\n");
    }

}

//main function for implementation
void KruskalAlgo(){

    // printf("\n\tImplementation of Kruskal's Algorithm\n");
    printf("\n\nThe edges of Minimum Cost Spanning Tree are\n");
    printf("\n\nedges\tweight\n");
    while (x < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find_node(u);
        v = find_node(v);
        if (set_union(u, v))
        {
            // printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            printf("(%d,%d)\t%d\n",a,b,min);
            x++;
            mincost += min;
        }
        graph[a][b] = graph[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", mincost);
}
int  main()
{
    takeInput();
    KruskalAlgo();
    
    
    return 0;
}

/*
0 1 7 10 5
1 0 3 0 0
7 3 0 4 0
10 0 4 0 2
5 0 0 2 0
*/