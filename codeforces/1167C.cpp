//#include <bits/stdc++.h>
#include <iostream> 
#include <algorithm>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m;
vector<int> id, sz;

int find(int p){ return id[p] = (id[p] == p? p:find(id[p])); }

void une(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q; sz[q]+=sz[p];
}

int main(){ _
    cin >> n >> m;
    id = vector<int> (n+1), sz = vector<int> (n+1, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        vector<int> group(k);
        for(int&g:group) cin >> g;
        for(int j = 0; j < k-1; j++) une(group[j], group[j+1]);
    }
    for(int i = 1; i < n+1; i++){
        if(i == n) cout << sz[id[i]] << endl;
        else cout << sz[id[i]] << " ";
    }
    return 0;
}