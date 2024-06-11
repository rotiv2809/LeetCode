#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int vis[N];
vector<int> adj[N];
queue <int> q;

void bfs(int s){
    memset(vis, false, sizeof(vis));
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (auto v: adj[u]) if (!vis[v])
        {
            vis[v] = 1;
            q.push(v);
        }
    }
}