#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

tuple<int,int,int> bfs(int init, int tam, vector<vector<int>>& adj){
    queue<int> q;
    vector<int> parent(tam+1, -1);
    vector<int> dist(tam+1, 1);
    parent[init] = 0;
    q.push(init);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto&a:adj[u]){
            if(parent[a] != -1) continue;
            dist[a] = dist[u]+1;
            parent[a] = u;
            q.push(a);
        }
    }
    tuple<int,int,int> ans;
    int mais_distante = -INF;
    int idx_mais_distante = -1;
    for(int i = 1; i < tam+1; i++){
        if(dist[i] > mais_distante){
            mais_distante = dist[i];
            idx_mais_distante = i;
        }
    }
    int pai = idx_mais_distante;
    int count = 0;
    while(count < mais_distante/2){
        pai = parent[pai];
        count++;
    }
int meio = pai;
    return {mais_distante, idx_mais_distante, meio};
}

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<vector<int>> circ(n+1), quad(m+1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        circ[a].push_back(b);
        circ[b].push_back(a);
    }
    for(int i = 0; i < m-1; i++){
        int a, b; cin >> a >> b;
        quad[a].push_back(b);
        quad[b].push_back(a);
    }
    auto [mais_prof_c, idx_prof_c, aux_c] = bfs(1, n, circ);
    auto [dim_c, idx_dim_c, meio_c] = bfs(idx_prof_c, n, circ);
    auto [mais_prof_q, idx_prof_q, aux_q] = bfs(1, m, quad);
    auto [dim_q, idx_dim_q, meio_q] = bfs(idx_prof_q, m, quad);
    cout << meio_c << " " << meio_q << endl;
    return 0;
}
