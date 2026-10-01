#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> dist_linha, parent, dist_pesos;
priority_queue<int> candidatos;
int x, m; 


void dfs(int x, vector<vector<pair<int,int>>>& adj){
    for(auto [n_u, n_c] : adj[x]){
        if(parent[x] == n_u) continue;
        else if(parent[n_u] == -1){
            parent[n_u] = x;
            dist_linha[n_u] = dist_linha[x] + n_c;
            dfs(n_u, adj);
        }
        else{
            int tam_ciclo = dist_linha[x] + n_c - dist_linha[n_u];
            if(tam_ciclo >= m) candidatos.push(-(tam_ciclo+ 2*dist_pesos[n_u]));
        }
    }
}

int main(){
    int s, t;
    cin >> s >> t;
    vector<vector<pair<int,int>>> adj(s+1);
    for(int i = 0; i < t; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int q; cin >> q;
    while(q--){
        cin >> x >> m;
        dist_linha = vector<int>(s+1, 0);
        parent = vector<int>(s+1, -1);
        dist_pesos = vector<int>(s+1, INF);
        priority_queue<pair<int,int>> pq;
        pq.push({-0, x});
        while(!pq.empty()){
            auto [c, u] = pq.top(); pq.pop();
            c = -c;
            if(dist_pesos[u] <= c) continue;
            dist_pesos[u] = c;
            for(auto [n_u, n_c] : adj[u])
                if(dist_pesos[n_u] > n_c+c) pq.push({-(n_c+c), n_u});
        }
        parent[x] = 0;
        dfs(x, adj);
        if(candidatos.empty()){ cout << -1 << endl;}
        else cout << -candidatos.top() << endl;
        while(!candidatos.empty()) candidatos.pop();
    }
}