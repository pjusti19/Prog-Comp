#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;
vector<ll> nums;

vector<ll> seg;
vector<ll> lazy;

void apply(ll x, int p, int l, int r){
    lazy[p] += x;
    seg[p] += x * (r - l + 1);
    return;
}

void push(int p, int l, int r){
    if(lazy[p] == 0 or l == r) return;
    int m = (l+r)/2;
    apply(lazy[p], 2*p, l, m);
    apply(lazy[p], 2*p+1, m+1, r);
    lazy[p] = 0;
    return;
}

ll update(int a, int b, ll x, int p, int l, int r){
    if(a > r or b < l) return seg[p];
    if(a <= l and b >= r){
        apply(x, p, l, r);
        return seg[p];
    }
    push(p, l, r);
    int m = (l+r)/2;
    return seg[p] = update(a, b, x, 2*p, l, m) + update(a, b, x, 2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return 0;
    if(a <= l and b >= r) return seg[p];
    push(p, l, r);
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
}

int main(){ _ 
    int t; cin >> t;
    while(t--){
        int n, c; cin >> n >> c;
        nums = vector<ll>(n, 0);
        seg = vector<ll>(4*MAX, 0);
        lazy = vector<ll>(4*MAX, 0);
        while(c--){
            int tipo; cin >> tipo;
            if(tipo == 0){
                int p, q; ll v; cin >> p >> q >> v;
                p--; q--;
                update(p, q, v, 1, 0, n-1);
            }
            else{
                int p, q; cin >> p >> q;
                p--; q--;
                cout << query(p, q, 1, 0, n-1) << endl;
            }
        }
    }

    return 0;
}
