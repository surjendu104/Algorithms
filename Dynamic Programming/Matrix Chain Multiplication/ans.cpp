//TC : O(n^3)

#include <bits/stdc++.h>
using namespace std;

#define MAX 400

// long int m[MAX][MAX];
// int s[MAX][MAX];
// int p[MAX];

vector<vector<long int>>m(MAX,vector<long int>(MAX));
vector<vector<int>>s(MAX,vector< int>(MAX));
vector<int>p(MAX);



void optimalParenthisation(int i,int j){
    if(i==j){
        cout<<"A"<<i<<" ";
    }
    else{
        cout<<"(";
        optimalParenthisation(i,s[i][j]);
        optimalParenthisation(s[i][j]+1,j);
        cout<<")";
    }
}

void MatrixChainMultipliocation(int n)
{
    long int cost = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                m[i][j] = 0;

            for (int k = i; k < j; k++)
            {
                cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of matrix: ";
    cin>>n;

    cout<<"Enter the dimension of the matrices\n";
    for(int i=0;i<=n;i++){
        cout<<"p["<<i<<"]: ";cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            m[i][i]=0;
            m[i][j]=INT_MAX;
            s[i][j]=0;
        }
    }

    MatrixChainMultipliocation(n);

    cout<<"\nCost Matrix\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<m[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Minimum cost for multiplication: "<<m[1][n];

    cout<<"\nOptimal parentisation\n";
    optimalParenthisation(1,n);

}