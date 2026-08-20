#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll memo[110][100010];
int n, W; 
vector<int> v, w;

ll dp(int i, int peso){
    if(peso > W) return -LINF;
    if(i >= n) return 0;
    ll& p = memo[i][peso];
    if(p != -1) return p;
    return p = max(dp(i+1, peso+w[i])+v[i], dp(i+1, peso));
}

int main(){ _ 
    cin >> n >> W;
    w.resize(n); v.resize(n);
    for(int i = 0; i < n; i++) cin >> w[i] >> v[i];
    memset(memo, -1, sizeof memo);
    cout << dp(0,0) << endl;
    return 0;
}