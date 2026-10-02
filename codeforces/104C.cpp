#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> adj;
vector<int> father;
vector<bool> visited;
int cont = 0;

void dfs(int u, int f) {
    visited[u] = true;
    for(auto& x : adj[u]) {
        if(visited[x] && x != f) cont++;
        else if(!visited[x]) dfs(x, u);
    }
}

int main(){ _
    int n, m, a, b;
    cin >> n >> m;
    adj = vector<vector<int>>(n+1);
    father = vector<int>(n+1, 0);
    visited = vector<bool>(n+1, false);
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    bool conexo = true;
    for(int i = 1; i <= n; i++) if(!visited[i]) {conexo = false; break;}
    if(conexo and cont / 2 == 1) cout << "FHTAGN!" << endl;
    else cout << "NO" << endl;

    return 0;
}