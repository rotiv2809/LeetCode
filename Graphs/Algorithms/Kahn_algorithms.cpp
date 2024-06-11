#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int inc[N];
queue <int> q;
vector<int> adj[N];
vector<int> tsort;

int n, e, a, b;


int main(){
    cin >> n >> e;
    // contabilizar o numero de dependências de cada nó:
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        inc[b]++;
    }
    // criar a queue com os elementos sem dependencia
    for (int i = 1; i <= n; i++) if(inc[i] == 0)
    {
        q.push(i);
    }
    // loop para a ordenação topológica
    while(!q.empty()){
        int u = q.front(); q.pop();
        tsort.push_back(u);
        for (int v : adj[u])
        {
            if(inc[v] > 0 and --inc[v] == 0){
                q.push(v);
            }
            // pra mim tem que subtrair ainda, no slide ta assim então fé...
        }
    }
}
