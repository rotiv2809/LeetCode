#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

queue<int> q;
vector<int> adj[N];
int inc[N];
vector<int> tsort;

int n;

int main() {
    vector<int> auxiliar;
    string s;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s);
    // Remover partes desnecessárias da string
    size_t pos = s.find("=");
    if (pos != string::npos) {
        s = s.substr(pos + 1); // Remove 'edges = '
    }
    s.erase(remove(s.begin(), s.end(), '['), s.end()); // Remove '['
    s.erase(remove(s.begin(), s.end(), ']'), s.end()); // Remove ']'
    s.erase(remove(s.begin(), s.end(), ' '), s.end()); // Remove ' '

    stringstream ss(s);
    int a, b;
    char comma;

    // Ler os pares de números da string
    while (ss >> a >> comma >> b) {
        auxiliar.push_back(a);
        auxiliar.push_back(b);

        // Ler a vírgula que separa os pares, se houver
        ss >> comma;
    }

    // agora sim começa o problema

    // contabilizar o numero de dependências de cada nó:
    for (int i = 0; i < auxiliar.size(); i+=2)
    {
        adj[auxiliar[i]].push_back(auxiliar[i+1]);
        inc[auxiliar[i+1]]++;
    }
    // criar a queue com os elementos sem dependencia
    for (int i = 0; i < n; i++) if(inc[i] == 0)
    {
        cout << inc[i] << endl;
    }
    for (int i = 1; i <= auxiliar.size(); i++) if(inc[i] == 0)
    {
        q.push(i);
    }
    return 0;
}

