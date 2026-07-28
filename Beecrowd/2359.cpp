#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f3f;
int n, m, q;

int main(){ _ 
    while(cin >> n >> m >> q){
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            a--; b--;
            adj[a].push_back({b,w});
            adj[b].push_back({a,w});
        }
        vector<int> hosps(q);
        for(int& h:hosps) cin >> h;
        priority_queue<pair<int,int>> pq;
        vector<int> dist(n, INF);
        for(int& h:hosps) pq.push({-0, h-1});
        while(!pq.empty()){
            int d = -pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(dist[idx] <= d) continue;
            dist[idx] = d;
            for(auto& [n_idx, p]:adj[idx])
                if(dist[n_idx] > d + p) pq.push({-(d + p), n_idx});
        }
        int maior = -INF;
        for(auto& d:dist) maior = max(maior, d);
        cout << maior << endl;
    }
    return 0;
}