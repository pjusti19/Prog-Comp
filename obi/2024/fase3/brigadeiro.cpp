// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <numeric>
// #include <unordered_map>

// using namespace std;

// #define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n'

// typedef long long ll;

// const int INF = 0x3f3f3f3f;
// const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

// int n, k;
// ll t;
// vector<int> quant, amigos;
// ll memo[300][2700];

// ll dp(int i, int b){
//     if(i >= n) return 0;
//     if(b < 0) return LLINF;
//     ll&p = memo[i][b];
//     if(p != -1) return p;
//     return p = min(dp(i+1, b+quant[i]), dp(i+1, b));
// }
// int main() { _ 
//     cin >> n >> k >> t;
//     quant = amigos = vector<int> (n);
//     int tot = 0;
//     for(int&q:quant) {cin >> q; tot+=q;}
//     for(int i = 0; i < n; i++) cin >> amigos[i];
//     memset(memo, -1, sizeof memo);
//     for(int i = tot; i >= 0; i++){
//         if(dp(0, i) <= t) {cout << i << endl; break;}
//     }
//     return 0;
// }
// vou voltar nesse dps