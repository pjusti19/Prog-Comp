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
    vector<unordered_map<int,vector<int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int v, u, t; cin >> v >> u >> t;
        adj[u][t].push_back(v);
        adj[v][t].push_back(u);
    }
    int a, b; cin >> a >> b;
    vector<unordered_map<int, bool>> visited(n+1);
    priority_queue<tuple<int,int,int>> pq;
    vector<bool> trocou(n+1, false);
    pq.push({-0, a, 0});
    while(!pq.empty()){
        auto [c, idx, tipo] = pq.top();
        pq.pop();
        c = -c;
        if(visited[idx].count(tipo) > 0) continue;
        visited[idx][tipo] = true;
        if(idx == b) {cout << c << endl; return 0;}

        if(adj[idx].count(tipo) > 0)
            for(int n_idx : adj[idx][tipo]) pq.push({-c, n_idx, tipo});

        if(!trocou[idx]){
            trocou[idx] = true;
            for(auto mp : adj[idx]){
                int n_tipo = mp.first;
                for(int n_idx:adj[idx][n_tipo]) pq.push({-(precos[n_tipo]+c), n_idx, n_tipo});
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
