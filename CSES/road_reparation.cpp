#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> id, sz;
ll custo = 0;

int find(int p){ return id[p] = (id[p] == p? p: find(id[p]));}

void une(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
}
int main(){ _
    int n, m; cin >> n >> m;
    priority_queue<tuple<ll, int, int>> pq;
    id = vector<int> (n+1); sz =  vector<int> (n+1, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < m; i++){
        int a, b; ll c; cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    while(!pq.empty()){
        auto [c, a, b] = pq.top();
        c = -c;
        pq.pop();
        if(find(a) == find(b)) continue;
        une(a, b); custo+=c;
        if(sz[find(a)] == n) {cout << custo << endl; return 0;}
    }
    cout << "IMPOSSIBLE" << endl;
}