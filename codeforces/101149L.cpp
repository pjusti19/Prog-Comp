#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m, a, b;

void bfs(int start, vector<vector<int>>&matriz, vector<int>&dist){
    queue<int> q;
    vector<bool> visited(n+1, false);
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto&m:matriz[u]){
            if(visited[m]) continue;
            q.push(m);
            dist[m] = dist[u]+1;
            visited[m] = true;
        }
    }
}

int main(){ _ 
    cin >> n >> m >> a >> b;
    vector<vector<int>> adj(n+1), radj(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        radj[y].push_back(x);
    }
    vector<int> distZero(n+1,INF), distA(n+1,INF), distB(n+1,INF);
    bfs(0, adj, distZero);
    bfs(a, radj, distA);
    bfs(b, radj, distB);
    int ans = INF;
    for(int i = 0; i < n+1; i++) ans = min(distZero[i]+distA[i]+distB[i], ans);
    cout << ans << endl;
    return 0;
}
