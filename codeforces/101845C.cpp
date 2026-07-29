#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f3;

int main(){ _ 
    string s, t;
    int m;
    cin >> s >> t >> m;
    vector<vector<pair<int,int>>> adj(128);
    for(int i = 0; i < m; i++){
        char a, b;
        int c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    int custo_total = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == t[i]) continue;
        priority_queue<pair<int,int>> pq;
        vector<int> custo(128, INF);
        int novo_custo = -1;
        pq.push({-0, s[i]});
        while(!pq.empty()){
            auto [c, idx] = pq.top();
            c = -c;
            pq.pop();
            if(custo[idx] <= c) continue;
            custo[idx] = c;
            if(idx == t[i]) {novo_custo = c; break;}
            for(auto [n_i, n_c]: adj[idx])
                if(n_c + c < custo[n_i]) pq.push({-(n_c + c), n_i});
        }
        if(novo_custo == -1) {cout << -1 << endl; return 0;}
        custo_total += novo_custo;
    }
    cout << custo_total << endl;
    return 0;
}