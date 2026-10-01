#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int INF = 0x3f3f3f3f;

vector<int> id, sz;

int find(int p) { return id[p] = (id[p] == p? p : find(id[p]));}

void une(int p, int q) { 
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q; sz[q] += sz[p];
}

int main(){ _ 
    int n; cin >> n;
    vector<int> alturas(n);
    for(int&a:alturas) cin >> a;
    vector<pair<int,int>> ordem;
    for(int i = 0; i < n; i++) ordem.push_back({alturas[i], i});
    sort(ordem.rbegin(), ordem.rend());
    id = vector<int> (n), sz = vector<int> (n, 1);
    iota(id.begin(), id.end(), 0);
    int c = 0, ans = -INF;
    for(auto &o:ordem){
        int h = o.first, u = o.second; 
        c++;
        if(u-1 >= 0 and alturas[u-1] >= h and find(u) != find(u-1)) {une(u, u-1), c--;}
        if(u+1 < n and alturas[u+1] >= h and find(u) != find(u+1)) {une(u, u+1), c--;}
        ans = max(ans, c);
    }
    cout << ans+1 << endl;
}