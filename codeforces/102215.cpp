//https://codeforces.com/gym/102215/problem/J

#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

    int n;
    cin >> n;
    vector<ll> t(n), p(n);
    ll a, b, c;
    for(ll i = 0; i < n; i++) {
        cin >> a >> b >> c;
        t[i] = a+b+c;
        p[i] = min({a+b, a+c, b+c});
    }
    vector<ll> d = p;
    sort(p.begin(), p.end());
    for(int i = 0; i < n; i++) {
        ll x = upper_bound(p.begin(), p.end(), t[i] - 2) - p.begin();
        if(t[i] - 2 < d[i]) cout << x;
        else cout << x - 1;
        cout << " ";
    }

    return 0;
}