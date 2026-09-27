#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> nums;
vector<int> prefix;
int memo[10000][10000];
int N, K, C;

int dp(int i, int k){
    if(k == K) return 0;
    if(i > N-C) return INF;
    int&p = memo[i][k];
    if(p != -1) return p;
    return p = min(dp(i+1, k), dp(i+C, k+1)+(prefix[i+C]-prefix[i]));
}

int main(){ _ 
    cin >> N >> K >> C;
    nums = vector<int>(N);
    prefix = vector<int>(N+1, 0);
    for(int&nu:nums) cin >> nu;
    for(int i = 0; i < N; i++) prefix[i+1] = prefix[i] + nums[i];
    memset(memo, -1, sizeof memo);
    int res = dp(0,0);
    cout << prefix[N] - res << endl;
    return 0;
}