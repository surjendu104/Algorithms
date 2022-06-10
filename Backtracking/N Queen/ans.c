#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int board[20], count = 1;

/* Fuunction to check the position is safe for the queen to place
row indecates the queen number and n represents the possible positions*/
int place(int row, int col)
{
    int i;
    for (i = 1; i <= row - 1; i++)
    {
        if (board[i] == col)
            return 0;
        else
        {
            if (abs(board[i] - col) == abs(i - row))
                return 0;
        }
    }
    return 1;
}
// Function for printing solution
void print(int n)
{
    printf("Solution no %d \n\n", count++);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i] == j)
            {
                printf(" Q ");
            }
            else
            {
                printf(" _ ");
            }
        }
        printf("\n\n");
    }
}

void queen(int row, int n)
{
    int col;
    for (col = 1; col <= n; col++)

    {
        if (place(row, col))
        {
            board[row] = col;
            if (row == n)
            {
                print(n);
            }
            else
            {
                queen(row + 1, n);
            }
        }
    }
}

int main()
{
    int n, i, j;
    printf("ENter the no of queens: ");
    scanf("%d", &n);
    queen(1, n);

    return 0;
}