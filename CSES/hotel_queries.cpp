#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2*1e5+10;

vector<ll> rooms, groups;
ll seg[4*MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = rooms[l];
    int m = (l+r)/2;
    return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
}

ll update(int i, ll x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r) return seg[p] -= x;
    int m = (l+r)/2;
    return seg[p] = max(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
}

int query(ll x, int p, int l, int r){
    if(l == r) return l;
    int m = (l+r)/2;
    if(seg[2*p] < x) return query(x, 2*p+1, m+1, r);
    else return query(x, 2*p, l, m);
}

int main(){ _ 
    int n, m; cin >> n >> m;
    rooms = vector<ll> (n);
    groups = vector<ll> (m);
    for(ll&r:rooms) cin >> r;
    for(ll&g:groups) cin >> g;
    build(1, 0, n-1);
    for(ll&g:groups){
        if(g > seg[1]) cout << 0 << " ";
        else{
            int hotel = query(g, 1, 0, n-1);
            update(hotel, g, 1, 0, n-1);
            cout << hotel+1 << " ";
        } 
    }
    cout << endl;
    return 0;
}
