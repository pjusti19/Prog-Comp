#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const ll maximo = 10000;
int main(){ _ 
    ll n, m; cin >> n >> m;
    ll tam = min(n,maximo);
    vector<int> ans(tam);
    for(int i = 0; i < tam; i++) ans[i] = i;
    vector<ll> ts(m);
    for(auto&t:ts) cin >> t;
    for(int i = m-1; i >= 0; i--){
        for(int j = 0; j < tam and ans[j] < n; j++) ans[j] += ans[j] / (ts[i]-1);
    }
    for(int i = 0; i < tam and ans[i] < n; i++) cout << ans[i]+1 << endl;
    
    return 0;
}