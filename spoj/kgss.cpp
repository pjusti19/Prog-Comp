#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2*1e5+10;
ll nums[MAX];
pair<ll,ll> seg[4*MAX];

pair<ll,ll> build(int p, int l, int r){
    if(l == r) return seg[p] = {nums[l], 0};
    int m = (l+r)/2;
    array<int,4> maiores;
    auto par1 = build(2*p, l, m);
    auto par2 = build(2*p+1, m+1, r);
    maiores[0] = par1.first; maiores[1] = par1.second; maiores[2] = par2.first; maiores[3] = par2.second;
    sort(maiores.begin(), maiores.end());
    return seg[p] = {maiores[3], maiores[2]};
}

pair<ll, ll> update(int i, ll x, int p, int l, int r){
    if(l > i or r < i) return seg[p];
    if(l == r) return seg[p] = {x, 0};
    int m = (l+r)/2;
    array<int,4> maiores;
    auto par1 = update(i, x, 2*p, l, m);
    auto par2 = update(i, x, 2*p+1, m+1, r);
    maiores[0] = par1.first; maiores[1] = par1.second; maiores[2] = par2.first; maiores[3] = par2.second;
    sort(maiores.begin(), maiores.end());
    return seg[p] = {maiores[3], maiores[2]};
}

pair<ll,ll> query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return {0, 0};
    if(a <= l and b >=r) return seg[p];
    int m = (l+r)/2;
    array<int,4> maiores;
    auto par1 = query(a, b, 2*p, l, m);
    auto par2 = query(a, b, 2*p+1, m+1, r);
    maiores[0] = par1.first; maiores[1] = par1.second; maiores[2] = par2.first; maiores[3] = par2.second;
    sort(maiores.begin(), maiores.end());
    return {maiores[3], maiores[2]};
}

int main(){ _ 
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    build(1, 0, n-1);
    int q; cin >> q;
    while(q--){
        char t; cin >> t;
        if(t == 'U'){
            int i; ll x; cin >> i >> x;
            i--;
            update(i, x, 1, 0, n-1);
        }
        else{
            int a, b; cin >> a >> b;
            a--; b--;
            auto maiores = query(a, b, 1, 0, n-1);
            cout << maiores.first+maiores.second << endl;
        }
    }
    return 0;
}
