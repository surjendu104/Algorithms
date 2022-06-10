#include <stdio.h>
#include <stdlib.h>
#define MAX 100

const int READY = 0;
const int WAITING = 1;
const int PROCESSED = 2;

int STATUS[MAX];

int arr[MAX], top;
int isEmpty()
{
    if (top <= -1)
        return 1;
    return 0;
}
int isFull()
{
    if (top >= MAX - 1)
        return 1;
    return 0;
}

void push(int val)
{
    if (isFull())
    {
        printf("\nOverFlow\n");
        return;
    }
    top++;
    arr[top] = val;
}

int pop()
{
    int a = -1;
    if (isEmpty())
    {
        printf("\nStack UnderFlow");
    }
    else
    {

        a = arr[top];
        top--;
    }
    return a;
}

int main()
{

    int graph[MAX][MAX];
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int src;
    printf("\nEnter the source node: ");
    scanf("%d", &src);
    push(src);

    for (int i = 0; i < n; i++) // initially all node in ready state
    {
        STATUS[i] = READY;
    }
    printf("\nDFS result is\n");
    while (!isEmpty())
    {
        int x = arr[top];
        pop();
        if (STATUS[x] == READY)
        {

            int temp=x;
            STATUS[x] = WAITING;
            printf("%d  ", x);
        }

        // printf("%d  ",x);
        STATUS[x] = PROCESSED;
        for (int i = 0; i < n; i++)
        {
            if (graph[x][i] > 0 && STATUS[i] == READY)
            {
                push(i);
            }
        }
    }

    return 0;
}

// Test adj matrix
/*
0 1 0 0 1 0 0 0
1 0 0 0 0 1 0 0
0 0 0 1 0 1 0 0
0 0 1 0 0 0 1 1
1 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0
0 1 1 0 0 0 1 0
0 0 0 1 0 1 0 1
0 0 0 1 0 0 1 0



0 1 1 1 0 0 0 0 0
1 0 0 1 0 0 0 0 0
1 0 0 0 1 1 0 0 0
1 1 0 0 0 1 1 0 0
0 0 1 0 0 1 0 1 0
0 0 1 1 1 0 1 1 0
0 0 0 1 0 1 0 0 0
0 0 0 0 1 1 0 0 1
0 0 0 0 0 0 0 0 0


0 1 0 1 0 0 0
1 0 1 0 0 1 1
0 1 0 1 1 1 0
1 0 1 0 1 0 0
0 0 1 1 0 0 1
0 1 1 0 0 0 0
0 1 0 0 1 0 0
*/