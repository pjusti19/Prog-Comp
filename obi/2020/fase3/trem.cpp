#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int e, r; cin >> e >> r;
    vector<vector<pair<int,int>>> adj(e+1);
    for(int i = 0; i < r; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int k; cin >> k;
    while(k--){
        int x, t; cin >> x >> t;
        // dijkstra
        priority_queue<pair<int,int>> pq;
        vector<int> dist(e+1, INF);
        pq.push({-0, x});
        while(!pq.empty()){
            auto [p, u] = pq.top();
            pq.pop();
            p = -p;
            if(dist[u] <= p) continue;
            dist[u] = p;
            for(auto& [n_u, n_p]: adj[u])
                if(dist[n_u] > n_p+p) pq.push({-(n_p+p), n_u});
        }
        // dfs
        vector<bool> visited(e+1, false);
        vector<int> dist_(e+1, 0);
        priority_queue<int> candidatos;

        function<void(int,int)> dfs = [&](int u, int pai){
            visited[u] = true;
            for(auto [n_u, c] : adj[u]){
                if(n_u == pai) continue;
                if(!visited[n_u]){
                    dist_[n_u] = dist_[u] + c;
                    dfs(n_u, u);
                } else {
                    int tam_ciclo = dist_[u] + c - dist_[n_u];
                    if(t <= tam_ciclo)
                        candidatos.push(-(2*dist[n_u] + tam_ciclo));
                }
            }
        };
        dfs(x, 0);

        cout << (candidatos.empty() ? -1 : -candidatos.top()) << "\n";
    }
    return 0;
}
