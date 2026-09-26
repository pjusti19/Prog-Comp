#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int l, c, p; cin >> l >> c >> p;
    vector<pair<int,int>> pretas(p);
    map<pair<int,int>, bool> permitidas;
    map<pair<int,int>, int> bloqueios;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}; 
    for(int i = 0; i < p; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        pretas[i] = {a, b};
        for(int i = 0; i < 4; i++){
            if(a+dy[i] < 0 or a+dy[i] >= l or b + dx[i] < 0 or b+dx[i] >= c) continue;
            permitidas[{a+dy[i], b+dx[i]}] = true;
        }
    }
    for(auto&p:permitidas){
        auto [a , b] = p.first;
        for(int i = 0; i < 4; i++){
            if(a+dy[i] < 0 or a+dy[i] >= l or b + dx[i] < 0 or b+dx[i] >= c) continue;
            bloqueios[{a, b}] += 1;
        }
    }
    priority_queue<pair<int,int>> pq;
    for(auto&p:permitidas){
        auto [a , b] = p.first;
        int idx = a*c + b;
        pq.push({-bloqueios[{a, b}],idx});
    }
    for(auto&p:pretas) permitidas[{p.first, p.second}] = false;
    int ans = 0;
    while(!pq.empty()){
        auto [bq, idx] = pq.top();
        pq.pop();
        int a = idx / c;
        int b = idx % c;
        if(permitidas[{a, b}] == false) continue;
        ans++;
        for(int i = 0; i < 4; i++){
            if(a+dy[i] < 0 or a+dy[i] >= l or b + dx[i] < 0 or b+dx[i] >= c) continue;
            permitidas[{a+dy[i], b+dx[i]}] = false;
        }
    }
    cout << ans << endl;
    return 0;
}
