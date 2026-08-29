#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2*1e5+10;

vector<pair<ll,ll>> v(MAX);
vector<pair<ll,ll>> seg(4*MAX);

pair<ll,ll> update(int i, pair<ll,ll> x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l+r)/2;
    pair<ll,ll> e = update(i, x, 2*p, l, m);
    pair<ll,ll> d = update(i, x, 2*p+1, m+1, r);
    return seg[p] = {max(e.first, d.first), min(e.second, d.second)};
}

pair<ll,ll> build(int p, int l, int r){
    if(l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    pair<ll,ll> e = build(2*p, l, m);
    pair<ll,ll> d = build(2*p+1, m+1, r);
    return seg[p] = {max(e.first, d.first), min(e.second, d.second)};
}

pair<ll, ll> query(int a, int b, int p, int l, int r){
    if(l <= a and b <= r) return seg[p];
    if(b < l or a > r) return {-LINF, LINF};
    int m = (l+r)/2;
    pair<ll,ll> e = query(a, b, 2*p, l, m);
    pair<ll,ll> d = query(a, b, 2*p+1, m+1, r);
    return {max(e.first, d.first), min(e.second, d.second)};
}

int main(){ _ 
    int n, q; cin >> n >> q;
    for(int i = 1; i < n+1; i++){
        ll a, b; cin >> a >> b;
        v[i] = {a,b};
    }
    build(1, 1, n);
    while(q--){
        char c; cin >> c;
        if(c == 'C'){
            int i; ll l, r; cin >> i >> l >> r;
            update(i, {l, r}, 1, 1, n);
        }
        else{
            int a, b; cin >> a >> b;
            pair<ll,ll> intervalo = query(a, b, 1, 1, n);
            if(intervalo.first > intervalo.second) cout << 0 << endl;
            else cout << intervalo.second - intervalo.first + 1 << endl; 
        }
    }
    return 0;
}
