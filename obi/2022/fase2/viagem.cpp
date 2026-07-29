#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){_

    int v, n, m; cin >> v >> n >> m;
    vector<vector<tuple<int,int,int>>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b, t, p; cin >> a >> b >> t >> p;
        adj[a].push_back({b, t, p});
        adj[b].push_back({a, t, p});
    }
    int init, dest; cin >> init >> dest;
    priority_queue<tuple<int,int,int>> pq;
    vector<vector<int>> tempos(n+1, vector<int>(v+1, INF));
    pq.push({-0, -0, init});
    int menor = -1;
    while(!pq.empty()){
        auto [t, c, i] = pq.top();
        t = -t; c = -c;
        pq.pop();
        if(tempos[i][c] <= t) continue;
        tempos[i][c] = t;
        if(i == dest) {menor = t; break;}
        for(auto& [v_i, v_t, v_c]:adj[i])
            if(v_c + c <= v and v_t + t < tempos[v_i][v_c + c]) pq.push({-(v_t + t), -(v_c + c), v_i});
    }
    cout << menor << endl;
    return 0;
}