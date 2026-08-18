#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> id, sz;

int find(int p) { return id[p] = (id[p] == p? p: find(id[p]));}

void une(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p]; 
}

int main(){ _ 
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b; ll c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i = 0; i < q; i++){
        id = vector<int> (n+1), sz = vector<int> (n+1, 1);
        iota(id.begin(), id.end(), 0);
        int k, v; cin >> k >> v;
        vector<bool> visited(n+1, false);
        visited[v] = true;
        queue<pair<int,ll>> qu;
        for(auto&ad: adj[v]) qu.push(ad);
        while(!qu.empty()){
            auto [u, c] = qu.front();
            qu.pop();
            visited[u] = true;
            if(c >= k and find(u)!=find(v)) une(u, v);
            for(auto&ad:adj[u]){
                auto [n_u, n_c] = ad;
                if(visited[n_u]) continue;
                qu.push({n_u, min(n_c, c)});
            }
        }
        cout << sz[find(v)]-1 << endl;
    }
    return 0;
}