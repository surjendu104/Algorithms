//TC : O(n^3)

#include <stdio.h>
#include <limits.h>
#define INF 999999999

long int m[20][20];//For storing multiplication cost
int s[20][20];//For the  K value for minimul multiplication 
int p[20];//To store the dimentions of each matrix

void print_optimal_paren(int i, int j)
{
    if (i == j)
        printf(" A%d ", i);
    else
    {
        printf("(");
        print_optimal_paren(i, s[i][j]);
        print_optimal_paren(s[i][j] + 1, j);
        printf(")");
    }
}

void MatrixChainMultiplication(int n)
{
    long int q;
    int k, i, j;
    for (i = n; i > 0; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                m[i][j] = 0;
            else
            {
                for (k = i; k < j; k++)
                {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
}

//Thi sfunction can also compute the minimum number of numtiplication
/* int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) +MatrixChainOrder(p, k + 1, j) +p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return min;
} */

int main()
{
    int k, n, i, j;
    printf("Enter the no. of matrices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
        {
            m[i][i] = 0;
            m[i][j] = INF;
            s[i][j] = 0;
        }
    printf("\nEnter the dimensions: \n");
    for (k = 0; k <= n; k++)
    {
        printf("P%d: ", k);
        scanf("%d", &p[k]);
    }

    MatrixChainMultiplication(n);

    printf("\n************Cost Matrix M*************\n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            // printf("m[%d][%d]: %ld\n", i, j, m[i][j]);
            printf("%ld\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n***************************************\n");

    i = 1, j = n;

    printf("\n************Multiplication Sequence*****\n");
    print_optimal_paren(i, j);
    printf("\n***************************************\n");

    printf("\nMinimum number of multiplications is : %d ",m[1][n]);
    return 0;
}
// MatrixChainOrder(p, 1, n)