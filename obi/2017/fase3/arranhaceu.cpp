#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

int seg [4*MAX];
vector<int> moradores;

int build(int p, int l, int r){
    if(l == r) return seg[p] = moradores[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m)+build(2*p+1, m+1, r);
}

int update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m)+update(i, x, 2*p+1, m+1, r);
}

int query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return 0;
    if(a <= l and b >= r) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m)+query(a, b, 2*p+1, m+1, r);
}

int main(){ _ 
    int n, q; cin >> n >> q;
    moradores = vector<int> (n);
    for(int&m:moradores) cin >> m;
    build(1, 0, n-1);
    while(q--){
        int t; cin >> t;
        if(t == 0){
            int k, p; cin >> k >> p;
            update(k-1, p, 1, 0, n-1);
        }
        else{
            int k; cin >> k;
            cout << query(0, k-1, 1, 0, n-1) << endl;
        }
    }
    return 0;
}
