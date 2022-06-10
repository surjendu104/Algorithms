#include <stdio.h>
#include <stdlib.h>
#define MAX 400
const int READY = 0;
const int WAITING = 1;
const int PROCESSED = 2;

int STATUS[MAX];
/************************   QUEUE IMPLEMENTATION    *************************/

int arr[MAX];
int Front = -1, Rear = -1;

int isEmpty()
{
    if (Front == Rear)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if (Rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(int val)
{
    if (isFull())
    {
        printf("This Queue is full\n");
    }
    else
    {

        Rear++;
        arr[Rear] = val;
    }
}

int dequeue()
{
    int a = -1;
    if (isEmpty())
    {
        printf("This Queue is empty\n");
    }
    else
    {
        Front++;
        a = arr[Front];
    }
    return a;
}
/*******************************************************************************************/
int main()
{

    // BFS implementation

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

    for (int i = 0; i < n; i++) // initially all node in ready state
    {
        STATUS[i] = READY;
    }

    printf("\nPrinting the BFS result\n");

    /*SOurce node*/
    int src;
    printf("\nEnter the source node: ");
    scanf("%d", &src);
    enqueue(src);
    STATUS[src] = WAITING; // First source/starting node pushed to queue and in WAITING

    while (!isEmpty())
    {
        int x = dequeue();
        printf("%d\t", x);

        // This one will traverse all children of node -- x
        for (int i = 0; i < n; i++)
        {
            if (graph[x][i] == 1 && STATUS[i] == READY)
            {
                // pushing node to traverse its children;
                enqueue(i);

                STATUS[i] = WAITING; // make their status to WAITING
            }
        }

        // After the loop "x"  is completely traversed,so status is PROCESSED
        STATUS[x] = PROCESSED;
    }
    printf("\n");
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