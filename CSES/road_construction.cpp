#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int INF = 0x3f3f3f3f;

vector<int> id, sz;

int find(int p) { return id[p] = (id[p] == p? p: find(id[p]));}
int maior = -INF;

void une(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
    maior = max(maior, sz[q]);
}

int main(){ _ 
    int n, m; cin >> n >> m;
    id = vector<int> (n+1), sz = vector<int> (n+1,1);
    iota(id.begin(), id.end(), 0);
    vector<vector<int>> adj(n+1);
    int c = n;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(find(a) != find(b)) {une(a, b); c--;}
        cout << c << " " << maior << endl;
    }
    return 0;
}