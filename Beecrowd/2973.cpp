#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, c, t;
vector<ll> sacos;

bool check(ll chute){
    int comp = 1;
    ll comidas = chute*t;
    int cont = 0;
    while(cont < n){
        if(comidas >= sacos[cont]){            
            comidas -= sacos[cont];
            cont++;
        }
        else{
            comp++;
            comidas = chute*t;
        }
        if(comp > c) return false;
    }
    return true;
}

int main(){ _ 
    cin >> n >> c >> t;
    for(int i = 0; i < n; i++){
        ll p; cin >> p;
        sacos.push_back(p);
    }
    ll l = 0, r = 1e9+10;
    while(l < r){
        ll m = (l+r)/2;
        if(!check(m)) l = m+1;
        else r = m;
    }
    cout << l << endl;
    return 0;
}

// procurando o primeiro true;