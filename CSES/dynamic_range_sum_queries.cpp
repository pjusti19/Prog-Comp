#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2*1e5+10;
ll nums[MAX];
ll seg[4*MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = nums[l];
    int m = (l+r)/2;
    return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
}

ll update(int i, ll x, int p, int l, int r){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l+r)/2;
    return seg[p] = update(i, x, 2*p, l, m)+update(i, x, 2*p+1, m+1, r);
}

ll query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return 0;
    if(a <= l and b >= r) return seg[p];
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m)+query(a, b, 2*p+1, m+1, r);
}

int main(){ _ 
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> nums[i];
    build(1, 0, n-1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int k; ll u; cin >> k >> u;
            k--;
            update(k, u, 1, 0, n-1);
        }
        else{
            int a, b; cin >> a >> b;
            a--; b--;
            ll s = query(a, b, 1, 0, n-1);
            cout << s << endl;
        }
    }
    return 0;
}
