#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5+1;

vector<pair<ll,ll>> coefs;
int BIT[MAX];

int main(){ _ 
    ll n, x1, x2; cin >> n >> x1 >> x2;
    coefs = vector<pair<ll,ll>>(n);
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        coefs[i] = {a, b};
    }

    return 0;
}
