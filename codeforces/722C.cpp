#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> id, sz, sum;
ll maior = 0;

ll find(ll p) {return id[p] = (id[p] == p ? p: find(id[p]));}

void une(ll p, ll q){
    p = find(p); q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    sz[q] += sz[p]; id[p] = q; sum[q] += sum[p];
}

int main(){ _ 
    int n; cin >> n;
    vector<ll> rem(n);
    vector<bool> colocados(n, false);
    id = vector<ll> (n); sz = vector<ll> (n, 1); sum = vector<ll> (n);
    iota(id.begin(), id.end(), 0);
    for(ll&s:sum) cin >> s;
    for(ll&r:rem) cin >> r;
    vector<ll> ans(n);
    for(int i = n-1; i >= 0; i--){
        ans[i] = maior;
        ll idx = rem[i]-1;
        if(idx+1 < n and colocados[idx+1]) une(idx, idx+1);
        if(idx-1 >= 0 and colocados[idx-1]) une(idx, idx-1);
        colocados[idx] = true; 
        maior = max(maior, sum[find(idx)]);
    }
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}
