// MATRIX COLOURING

#include <stdio.h>

int g[10][10], x[10], n, m, sol;

void write()
{
    int i;
    printf("Colouring solution number %d::", ++sol);
    printf("\nVertex \tColor\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d \t%d\n", i, x[i]);
    }
    printf("\n");
}

void next_colour(int k)
{
    int i;
    do
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }
        for (i = 1; i <= n; i++)
        {
            if (g[i][k] != 0 && x[k] == x[i])
            {
                break;
            }
        }
        if (i == (n + 1))
        {
            return;
        }
    } while (1);
}

void m_colouring(int k)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        next_colour(k);
        if (x[k] == 0)
        {
            return;
        }
        else if (k == n)
        {
            write();
        }
        else
        {
            m_colouring(k + 1);
        }
    }
}

void input()
{
    int i, j;
    printf("Enter number of vertex and colour::");
    scanf("%d %d", &n, &m);
    printf("Enter adjacency matrix::");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
}

void main()
{
    input();
    m_colouring(1);
    if (sol == 0)
    {
        printf("Need more than %d colour", m);
    }
    else
        printf("Total solution::%d", sol);
}