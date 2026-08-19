#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int x = 0; x < m; x++){
        int i, j, p; cin >> i >> j >> p;
        adj[i].push_back({j, p});
        adj[j].push_back({i, p});
    }
    int c; cin >> c;
    for(int i = 0; i < c; i++){
        int x, y; cin >> x >> y;
        priority_queue<pair<int,int>> pq;
        vector<int> dist(n+1, -INF);
        pq.push({INF, x});
        while(!pq.empty()){
            int p = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(dist[u] > p) continue;
            dist[u] = p;
            if(u == y) break;
            for(auto [n_u, n_p]:adj[u])
                if(min(n_p, p) > dist[n_u]) pq.push({min(n_p, p), n_u});
        }
        cout << dist[y] << endl;
    }

    return 0;
}