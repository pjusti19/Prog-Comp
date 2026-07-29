#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const ll INF = 4e18;

int main(){_ 

    int n, m; cin >> n >> m;
    vector<vector<pair<int,ll>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int v, u; ll w; cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }
    vector<ll> show_price(n+1);
    for(int i = 1; i < n+1; i++) cin >> show_price[i];
    priority_queue<pair<ll,int>> pq;
    vector<ll> price(n+1, INF); 
    for(int i = 1; i < n+1; i++) pq.push({-show_price[i], i});
    while(!pq.empty()){
        auto [p, idx] = pq.top();
        p = -p;
        pq.pop();
        if(price[idx] <= p) continue;
        price[idx] = p;
        for(auto [n_i, n_p] : adj[idx])
            if(price[n_i] > 2*n_p + p) {pq.push({-(p+2*n_p), n_i});}
    }
    for(int i = 1; i < n+1; i++){
        if(i == n) {cout << price[i] << endl;}
        else {cout << price[i] << " ";}
    }
    return 0;
}