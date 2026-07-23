#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

int n; 
vector atv(1e5, vector<int>(3));
ll memo[100010][4];

ll dp(int i, int j){
    if(i == n) return 0;
    ll& p = memo[i][j];
    if(p != -1) return p;
    if(j == 0) p = atv[i][j] + max(dp(i+1, 1), dp(i+1, 2));
    else if(j == 1) p = atv[i][j] + max(dp(i+1, 0), dp(i+1, 2));
    else p = atv[i][j] + max(dp(i+1, 0), dp(i+1, 1));
    return p;
}

int main(){_
    cin >> n;
    for(int i = 0; i < n; i++) cin >> atv[i][0] >> atv[i][1] >> atv[i][2];
    memset(memo, -1, sizeof memo);
    cout << max({dp(0,0), dp(0,1), dp(0,2)}) << endl;
    return 0;
}