#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, m, k; cin >> n >> m >> k;
    vector<int> precos(k+1);
    for(int i = 1; i < k+1; i++) cin >> precos[i];
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int v, u, t; cin >> v >> u >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    int a, b; cin >> a >> b;
    vector<int> dist(n+1,INF);
    vector<unordered_map<int, bool>> hist(n+1);
    priority_queue<tuple<int,int,int>> pq;
    pq.push({-0, a, 0});
    while(!pq.empty()){
        auto [c, idx, tipo] = pq.top();
        pq.pop();
        c = -c;
        if(hist[idx].count(tipo) > 0 and dist[idx] <= c) continue;
        dist[idx] = c;
        hist[idx][tipo] = true;
        if(idx == b) {cout << dist[idx] << endl; return 0;}
        for(auto [n_idx, n_tipo] : adj[idx]){
            int n_c = n_tipo == tipo? 0: precos[n_tipo];
            if(!(hist[n_idx].count(n_tipo) > 0 and dist[n_idx] < n_c+c)){ pq.push({-(n_c+c), n_idx, n_tipo});}
        }
    }

    cout << -1 << endl;

    return 0;
}
