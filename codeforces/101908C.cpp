#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2*1e5+1;

ll h, v;
unordered_map<ll,ll> ump_v, ump_h;
ll BIT_H[MAX], BIT_V[MAX];

void update(int i, ll x, ll* BIT){
    for(; i <= MAX; i += i & -i) BIT[i] += x;
}

ll prefix(int i, ll* BIT){
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret += BIT[i];
    return ret;
}

ll intersect(vector<ll>& vec, ll* BIT, unordered_map<ll,ll>& ump){
    ll ret = 0;
    int cont = 1;
    vector<ll> aux = vec;
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    for(ll& a:aux) ump[a] = cont++;
    for(int i = vec.size()-1; i >= 0; i--){
        ret += prefix(ump[vec[i]], BIT);
        update(ump[vec[i]], 1, BIT);
    }
    return ret;
}

int main(){ _ 
    ll x, y; cin >> x >> y;
    cin >> h >> v;
    vector<pair<ll,ll>> hs(h), vs(v);
    for(int i = 0; i < h; i++){
        ll a, b; cin >> a >> b;
        hs[i] = {a,b};
    }
    for(int i = 0; i < v; i++){
        ll a, b; cin >> a >> b;
        vs[i] = {a,b};
    }
    sort(hs.begin(), hs.end()); sort(vs.begin(), vs.end());
    vector<ll> fins_h(h), fins_v(v); 
    for(int i = 0; i < h; i++) fins_h[i] = hs[i].second;
    for(int i = 0; i < v; i++) fins_v[i] = vs[i].second;
    ll intersecoes = h*v + intersect(fins_h, BIT_H, ump_h) + intersect(fins_v, BIT_V, ump_v);
    cout << 1 + h + v + intersecoes << endl;
    return 0;
}
