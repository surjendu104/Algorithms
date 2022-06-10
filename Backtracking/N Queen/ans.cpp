#include<bits/stdc++.h>
using namespace std;

#define MAX 400

vector<int>board(MAX);

int count=0;

bool isSafe(int row,int col){
    for(int i=1;i<=row-1;i++){
        if(board[i]==col)return false;
        else if(abs(board[i]-col)==abs(i-row))return false;
    }
    return true;
}

void print(int n){
    
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n; j++)
        {
            if(board[i]==j)cout<<"Q ";
            else cout<<"_ ";
            /* code */
        }
        cout<<endl;
    }
    cout<<endl;
}

void queen(int row,int n){
    for(int i=1;i<=n;i++){
        if(isSafe(row,i)){
            board[row]=i;
            if(board[i]==n){
                // cout<<"Solution No: "<<count++ <<endl;
                print(n);return;
            }
            else queen(row+1,n);
        }
    }
}


int main(){

    int n;cin>>n;
    queen(1,n);
    return 0;
}