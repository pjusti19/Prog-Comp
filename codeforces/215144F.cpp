#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f;

int n,m,x;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int init){
    priority_queue<pair<int,int>> pq;
    vector<int> dist(n+1, INF);
    pq.push({-0, init});
    while(!pq.empty()){
        auto [d , i] = pq.top();
        d = -d;
        pq.pop();
        if(dist[i] <= d) continue;
        dist[i] = d;
        for(auto [n_i, n_d] : adj[i])
            if(dist[n_i] > n_d+d) pq.push({-(n_d+d), n_i});
    }
    return dist;
}

int main(){
    cin >> n >> m >> x;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> friends(x);
    for(auto&f:friends) cin >> f;
    vector<int> dist_friends = dijkstra(adj, 1);
    vector<int> dist_icecream = dijkstra(adj, n);
    int ans = INF;
    for(auto&f:friends) ans = min(ans, dist_friends[f]+dist_icecream[f]);
    cout << ans << endl;
}