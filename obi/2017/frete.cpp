#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int INF = 0x3f3f3f3f;

int main(){ _
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    priority_queue<pair<int,int>> pq;
    vector<int> dist(n+1, INF);
    pq.push({-0, 1});
    while(!pq.empty()){
        auto [c, v] = pq.top();
        c = -c;
        pq.pop();
        if(dist[v] <= c) continue;
        dist[v] = c;
        if(v == n) break;
        for(auto [n_v, n_c] : adj[v])
            if(dist[n_v] > n_c+c) pq.push({-(n_c+c), n_v});
    }
    
    cout << dist[n] << endl;
    
    return 0;
}