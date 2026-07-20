#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N, W;
vector<int> w, v;

ll memo[110][100010];

ll dp(int i, int s){
    if(s < 0) return -LINF;
    if(i == N) return 0;
    ll &p = memo[i][s];
    if(p != -1) return p;
    return p = max(dp(i+1, s), dp(i+1, s-w[i]) + v[i]);
}

int main()
{ _
    cin >> N >> W;
    w.resize(N); v.resize(N); 
    for(int i = 0; i < N; i++)
        cin >> w[i] >> v[i];
    
    memset(memo, -1, sizeof memo);

    cout << dp(0, W) << endl;

    return 0;
}