#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+1;

ll n;
vector<pair<ll,ll>> ys;
vector<ll> lims;
int BIT[MAX];
unordered_map<ll,ll> ump;

ll prefix(int i){
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret+=BIT[i];
    return ret;
}

void update(int i, ll x){for(; i < MAX; i += i & -i) BIT[i]+=x;}

ll intersect(){
    ll ret = 0;
    int cont = 1;
    vector<ll> aux = lims;
    sort(aux.begin(), aux.end());
    aux.erase(unique(aux.begin(), aux.end()), aux.end());
    for(ll&a:aux) ump[a] = cont++;
    for(int i = n-1; i >=0; i--){
        ret += prefix(ump[lims[i]]);
        update(ump[lims[i]], 1);
    }
    return ret;
}

int main(){ _ 
    ll x1, x2; cin >> n >> x1 >> x2;
    ys = vector<pair<ll,ll>>(n);
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        ys[i] = {a*x1+b, -(a*x2+b)};
    }
    sort(ys.begin(), ys.end());
    lims = vector<ll>(n);
    for(int i = 0; i < n; i++) lims[i] = -ys[i].second;
    cout << intersect() << endl;
    return 0;
}
