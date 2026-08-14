#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<string> amigos(n);
    unordered_map<string, bool> apareceu; apareceu.reserve(n*2); apareceu.max_load_factor(0.7);
    for(auto& a:amigos) cin >> a;
    for(int i = n-1; i >= 0 ; i--){
        if(!apareceu[amigos[i]]) {
            apareceu[amigos[i]] = true;
            cout << amigos[i] << endl;
        }
    }
    return 0;
}
