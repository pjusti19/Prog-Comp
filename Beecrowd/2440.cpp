//#include <bits/stdc++.h>
#include <iostream>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> sz, id;
int comps;

int find(int p){ return id[p] = ( id[p] == p? p : find(id[p]) );}

void une(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q; sz[q]+=sz[p];
    comps--;
}

int main(){ _ 
    int n, m;
    cin >> n >> m;
    id = vector<int>(n+1);
    iota(id.begin(), id.end(), 0);
    sz = vector<int> (n+1, 1);
    comps = n;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        une(a,b);
    }
    cout << comps << endl;
    return 0;
}
