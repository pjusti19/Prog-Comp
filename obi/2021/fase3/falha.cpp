#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

unordered_map<string,int> um;

int main(){ _ 
    int n; cin >> n;
    vector<string> senhas(n);
    for(int i = 0; i < n; i++){
        cin >> senhas[i];
        unordered_set<string> us;
        for(int j = 0; j < senhas[i].size(); j++){
            string construida;
            for(int k = j; k < senhas[i].size(); k++){
                construida.push_back(senhas[i][k]);
                us.insert(construida);
            }
        }
        for(auto&u:us) um[u]+=1;
    }
    int ans = -n;
    for(auto&s:senhas) ans += um[s];
    cout << ans << endl;
    return 0;
}