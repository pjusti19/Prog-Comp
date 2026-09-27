#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, t; cin >> n >> t;
    if(t == 0) cout << n << endl;
    else if(t == 1) cout << n*(n-1) << endl;
    else{
        ll ans = 0;
        for(int i = 2; i <= n; i++)
            ans += (i-1)*(n-i);
        cout << ans << endl;
    }
    return 0;
}
