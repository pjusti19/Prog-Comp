#include <iostream>
#include <queue>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<ll> carros(n), mecanicos(m);
    priority_queue<tuple<ll,ll,ll>> pq;
    for(ll&c:carros) cin >> c;
    for(ll&mec:mecanicos) cin >> mec;
    for(int i = 0; i < m; i++) pq.push({-0, mecanicos[i], 0});
    vector<ll> tempos(m);
    sort(carros.rbegin(), carros.rend());
    ll ans = 0;
    for(ll&c:carros){
        auto [p, e, n] = pq.top();
        pq.pop();
        p = -p;
        ans+= c*p;
        n++;
        pq.push({-(e*n), e, n});
    }
    cout << ans << endl;
    return 0;
}
