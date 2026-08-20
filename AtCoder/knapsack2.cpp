#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int N, W;
vector<int> v, w;
ll memo[110][101000];

ll dp(int i, int l){
    if(l == 0) return 0;
    if(l < 0 or i >= N) return LINF;
    ll& p = memo[i][l];
    if(p != -1) return p;
    return p = min(dp(i+1, l-v[i])+w[i], dp(i+1, l));
}
int main(){ _ 
    cin >> N >> W;
    v.resize(N); w.resize(N);
    int tot = 0;
    for(int i = 0; i < N; i++) {cin >> w[i] >> v[i]; tot+= v[i];}
    memset(memo, -1, sizeof memo);
    for(int i = tot; i >= 0; i--){
        if(dp(0, i) <= W){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}