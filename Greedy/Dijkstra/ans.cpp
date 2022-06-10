#include<bits/stdc++.h>
using namespace std;
#define MAX 400


vector<vector<int>>graph(MAX);
vector<int>dist(MAX),visited(MAX);
int n;
void Input(){
    cout<<"\nEnter the number of veritces: ";cin>>n;
    cout<<"\nEnter the adjacency matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>graph[i][j];
        }
        
    }

    cout<<"\nGiven adjacency Matrix\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    
}


int main(){


    return 0;
}