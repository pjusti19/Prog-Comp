#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const ll MAX = 1e9+7;
int main(){ _ 
    int n; cin >> n;
    ll f[10001];
    f[0] = f[1] = 1; f[2] = 5;
    for(int i = 3; i <= n; i++)
        f[i] = (f[i-1] + 4*f[i-2] + 2*f[i-3])%MAX;
    cout << f[n] << endl;
    return 0;
}
