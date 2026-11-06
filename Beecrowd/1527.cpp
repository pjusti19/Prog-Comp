//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz, poder;

int find(int p) { return id[p] = (id[p] == p? p:find(id[p]));}

void une(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q; sz[q] += sz[p]; poder[q] += poder[p];
}

int main(){ _ 
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 and m == 0) return 0;
        id = poder = vector<int> (n+1);
        iota(id.begin(), id.end(), 0);
        sz = vector<int> (n+1, 1);
        for(int i = 1; i <= n; i++) cin >> poder[i];
        int ans = 0;
        for(int i = 0; i < m; i++){
            int t, a, b; cin >> t >> a >> b;
            if(t == 1) une(a , b);
            else{
                int idr = find(1);
                int ida = find(a);
                int idb = find(b);
                if(ida != idr and idb != idr) continue;
                int outro = ida == idr? idb:ida;
                if(outro != idr and poder[idr] > poder[outro]) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
