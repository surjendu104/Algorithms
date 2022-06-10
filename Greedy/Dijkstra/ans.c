/*
    TC: O(V^2)
    SC: O(N)[For using visited array]
    For more:: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
int graph[MAX][MAX],n;

int dist[MAX],visited[MAX];


void takeInput(){
    printf("\nEnter the number of vertices: ");
    scanf("%d",&n); 
    printf("\n\nEnter the adjacency matrix(Enter 0 if there is no direct edge) : \n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&graph[i][j]);
        }
        
    }
}

int minimum_distance(int dist[],int visited[]){
    int min=INT_MAX,min_idx;

    for(int i=0;i<n;i++){
        if(!visited[i] && dist[i]<=min){
            min=dist[i];
            min_idx=i;
        }
    }
    return min_idx;
}

void print_solution(int dist[]){
    
    printf("\n\nVertex no. \tDistance from Source\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t\t%d\n",i,dist[i]);
    }
    
}

void DIjkstra_imp(int graph[][MAX],int s){

    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        visited[i]=0;
    }

    dist[s]=0;

    for (int i = 0; i < n-1; i++)
    {
        int x=minimum_distance(dist,visited);

        visited[x]=1;
        for (int j = 0; j < n; j++) 
        {
            if(!visited[j] && graph[x][j] && dist[x] != INT_MAX && dist[x]+graph[x][j]<dist[j]){
                dist[j]=dist[x]+graph[x][j];
            }
        }
    }   
    
    
}

int main(){
    int src;
    takeInput();
    printf("\n\nEnter the source vertex: ");scanf("%d",&src);

    printf("/*******************OUTPUT********************/");
    DIjkstra_imp(graph,src);
    print_solution(dist);
    return 0;
}




/*0 4 0 0 0 0 0 8 0
0 8 0 7 0 4 0 0 2
4 0 8 0 0 0 0 11 0
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0 */