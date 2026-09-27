// #include <bits/stdc++.h>

// using namespace std;

// #define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n'

// typedef long long ll;

// const int INF = 0x3f3f3f3f;
// const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
// const int MAX = 2*1e5+10;

// vector<ll> memo;
// ll seg[4*MAX];
// ll lazy[4*MAX];

// void apply(int p, ll x){
//     if(x == 0) return;
//     lazy[p] += x;
//     seg[p] += lazy[p];
//     lazy[p] = 0;
//     return;
// }

// void push(int p, int l, int r){
//     if(lazy[p] == 0 or l == r) return;
//     int m = (l+r)/2;
//     apply(2*p, lazy[p]);
//     apply(2*p+1, lazy[p]);
//     lazy[p] = 0;
//     return;
// }

// void update(ll i, ll x, int p, ll l, ll r){
//     if(i > r or i+x < l) return;
//     if(i >= l and i+x <= r){
//         apply(p, x-(i-l));
//         return;
//     }
//     push(p, l, r);
//     ll m = (l+r) / 2;
//     update(i, x, 2*p, l, m);
//     update(i, x, 2*p+1, m+1, r);
//     return;
// }

// ll query(int i, int p, int l, int r){
//     if(i > r or i < l) return 0;
//     if(l == r) return seg[p];
//     int m = (l+r)/2;
//     push(p, l, r);
//     return query(i, 2*p, l, m) + query(i, 2*p+1, m=1, r);
// }

// int main(){ _ 
//     int n, m; cin >> n >> m;
//     memo = vector<ll>(n, 0);
//     while(m--){
//         int t; cin >> t;
//         if(t == 1){
//             ll i, v; cin >> i >> v;
//             update(i, v, 0, 0, n-1);
//         }
//         else if(t == 2){
//             int i; ll v; cin >> i >> v;
//         }
//         else{
//             int i; cin >> i;
//         }
//     }
//     return 0;
// }
