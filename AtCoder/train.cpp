#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const ll INF = 4e18;

int main(){_ 

    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<vector<tuple<int,ll,ll>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b; ll t, k; cin >> a >> b >> t >> k;
        adj[a].push_back({b, t, k});
        adj[b].push_back({a, t, k});
    }
    priority_queue<pair<ll,int>> pq;
    vector<ll> time(n+1, INF);
    ll ans = -1;
    pq.push({-0, x});
    while(!pq.empty()){
        auto [t, i] = pq.top();
        t = -t;
        pq.pop();
        if(time[i] <= t) continue;
        time[i] = t;
        if(i == y) {ans = t; break;}
        for(auto [n_i, n_t, n_f] : adj[i]){
            ll w_t = (n_f-(t%n_f))%n_f;
            if(time[n_i] > t + n_t + w_t) pq.push({-(t + n_t + w_t), n_i});
        }
    }
    cout << ans << endl;
    return 0;
}