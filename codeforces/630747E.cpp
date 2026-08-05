#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int p, k, m, n;
vector<bool> ven(200010,false), ant(200010, false);
int memo[200010][2];
int dp(int idx, bool ta_envenenado){
    if(idx > p or (idx == p and ta_envenenado)) return 0;
    if(idx == p and !ta_envenenado) return 1;
    int &ref = memo[idx][ta_envenenado];
    if(ref != -1) return ref;
    if(ven[idx]) return ref = dp(idx+k, true) or dp(idx+1, true);
    if(ant[idx]) return ref = dp(idx+k, false) or dp(idx+1, false);
    return ref = dp(idx+k, ta_envenenado) or dp(idx+1, ta_envenenado);
}

int main(){ _ 
    cin >> p >> k >> m;
    for(int i = 0; i < m; i++){
        int idx; cin >> idx;
        ven[idx] = true;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        int idx; cin >> idx;
        ant[idx] = true;
    }
    memset(memo, -1, sizeof memo);
    if(dp(0, false)) cout << "Sim";
    else cout << "Nao";
    cout << endl;

   return 0;
}