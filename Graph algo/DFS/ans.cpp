#include <bits/stdc++.h>
using namespace std;
vector<int> visited(400, 0);
int n;
int graph[400][400];
void dfs(int i){
    cout<<i<<" ";
    visited[i]=1;
    for (int j = 0; j < n; j++)
    {
        if(graph[i][j]==1 && visited[j]==0)
            dfs(j);
    }
    
}
int main()
{

    cout << "\nEnter the number of verticies: ";
    cin >> n;

    cout << "Enter the adjacency matrix\n";
    for (int i = 0; i < n; i++)
    {
        // vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            cin>>graph[i][j];
        }
    }
    dfs(0);
    return 0;
}