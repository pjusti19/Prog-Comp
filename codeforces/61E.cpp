#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e6+1;

int n;
vector<ll> romanos, dir, esq;
ll BIT_D[MAX], BIT_E[MAX];
unordered_map<ll,ll> ump;

ll prefix(int i, ll* BIT){
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret+= BIT[i];
    return ret; 
}

void update(int i, ll x, ll* BIT) {for(; i < MAX; i += i & -i) BIT[i] += x;}

void direitos(ll* BIT){
    vector<ll> aux = romanos;
    int cont = 1;
    sort(aux.begin(), aux.end());
    for(ll&a:aux) ump[a] = cont++;
    for(int i = n-1; i >= 0; i--){
        dir[i] = prefix(ump[romanos[i]], BIT);
        update(ump[romanos[i]], 1, BIT);
    }
}

void esquerdos(ll* BIT){
    vector<ll> aux = romanos;
    sort(aux.begin(), aux.end());
    for(int i = 0; i < n; i++){
        esq[i] = i - prefix(ump[romanos[i]], BIT);
        update(ump[romanos[i]], 1, BIT);
    }
}

int main(){ _ 
    cin >> n;
    romanos = dir = esq = vector<ll>(n);
    for(ll&r:romanos) cin >> r;
    direitos(BIT_D);
    esquerdos(BIT_E);
    ll ans = 0;
    for(int i = 0; i < n; i++) ans+= dir[i]*esq[i];
    cout << ans << endl;
    return 0;
}
