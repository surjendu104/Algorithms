#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
#define ll long long
#define lld long long double
int primsAlgoFroMinimumSpanningTree()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> vis(n, 0);
    int sum = 0;
    while (pq.size())
    {
        auto it = pq.top();
        pq.pop();
        int edW = it.first;
        int node = it.second;

        if (vis[node])
            continue;
        vis[node] = 1;
        sum += edW;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int wt = it[1];
            if (!vis[adjNode])
                pq.push({wt, adjNode});
        }
    }
    return sum;
}
int main()
{
    int sum = primsAlgoFroMinimumSpanningTree();
    cout << "Total weight of minimul spanning tree : " << sum << '\n';
}