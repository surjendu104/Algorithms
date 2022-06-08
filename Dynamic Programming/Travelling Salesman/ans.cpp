#include <bits/stdc++.h>
using namespace std;
#define V 4

int graph[][V] = { { 0 ,10 ,15 ,20 },
                       { 5 ,0, 9, 10 },
                       { 6, 13, 0, 12 },
                       { 8, 8, 9, 0 } };
int VISITED=(1<<V)-1;
int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

//Through bit mask
int tsp(int m,int pos){
    if(m==VISITED)return graph[pos][0];
    

    int ans=INT_MAX;
    for (int city = 0; city < V; city++)
    {
        if((m&(1<<city))==0){
            int temp=graph[pos][city]+tsp(m|(1<<city),city);
            ans=min(ans,temp);
        }
    }
    return ans;
}
int main()
{
    /* int graph[][V] = { { 0, 10, 15, 20 },
                       { 5, 0, 9, 10 },
                       { 6, 13, 0, 12 },
                       { 8, 8, 9, 0 } }; */
    // int s = 0;
    // cout << travllingSalesmanProblem(graph, s) << endl;
    cout << "minimum cost : "<<tsp(1,0) << endl;
    return 0;
}
