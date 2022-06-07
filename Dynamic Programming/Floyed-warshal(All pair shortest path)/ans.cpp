//TC : O(n^3)

#include<bits/stdc++.h>
using namespace std;
#define MAX 400
#define INF 999

vector<vector<int>>a(MAX,vector<int>(MAX));
vector<vector<int>>cost(MAX,vector<int>(MAX));

int min(int a,int b){return (a<b)?a:b;}

int floyed_warshal(vector<vector<int>>&cost,vector<vector<int>>&a,int n){
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = cost[i][j];
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}

void print(vector<vector<int>>&cost,vector<vector<int>>&a,int n){
    cout<<"*********Given adjacency matrix*********\n";
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(a[i][j]==999)cout<<"INF\t";
            else{
                cout<<a[i][j]<<"\t";
            }

        }
        cout<<endl;
        
    }
    cout<<"\n ................................................\n ";
    cout<<"\n*****All the shortest paths obtained is******\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == 999)
                cout<<"\tinf";
            else
                cout<<"\t"<< a[i][j];
        printf("\n");
    }
    printf("\n ...............................................\n ");
}


int main(){
    int n;cout<<"Enter the number of vertices: ";cin>>n;

    cout<<"Enter the adjacency matrix(Enter 999 if there is no direct path)\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>cost[i][j];
        }
    }

    floyed_warshal(cost,a,n);
    print(cost,a,n);
}