#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k; 
vector<ll> tam;
ll memo[10000][3010];

ll dp(int idx, int c){
    if(idx >= n-1 and c < k or (3*(k-c) > n - idx)) return LINF;
    if(c == k) return 0;
    ll&p = memo[idx][c];
    if(p != -1) return p;
    return p = min(dp(idx+2, c+1)+abs(tam[idx]-tam[idx+1])*abs(tam[idx]-tam[idx+1]), dp(idx+1, c));
}

int main(){ _ 
    cin >> n >> k;
    tam = vector<ll> (n);
    memset(memo, -1, sizeof memo);
    for(ll&t:tam) cin >> t;
    sort(tam.begin(), tam.end());
    cout << dp(0,0) << endl;
    return 0;
}
 

