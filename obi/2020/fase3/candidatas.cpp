#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<ll> seq;
const int MAX = 1e5+10;
ll seg[4*MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = seq[l];
    int m = (l+r) / 2;
    return seg[p] = gcd(build(2*p, l, m), build(2*p+1, m+1, r));
}

ll update(int i, ll x, int p, int l, int r){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = gcd(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

ll query(int a, int b, int p, int l, int r){
    if(l > b or r < a) return 0;
    if(a <= l and b >= r) return seg[p];
    int m = (l+r)/2;
    return gcd(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

int main(){ _ 
    int n, m; cin >> n >> m;
    seq = vector<ll> (n);
    for(ll&s:seq) cin >> s;
    build(0, 0, n-1);
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        if(t == 1){
            int i; ll v; cin >> i >> v;
            update(i-1, v, 0, 0, n-1);
        }
        else{
            int e, d; cin >> e >> d;
            cout << query(e-1, d-1, 0, 0, n-1) << endl;
        }
    }
    return 0;
}

// ta errada rs