#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, p; cin >> n >> p;
    vector<pair<int,int>> pts(n);
    for(int i = 0 ; i < n; i++){
        int a, b; cin >> a >> b;
        pts[i] = {a, -b};
    }
    sort(pts.rbegin(), pts.rend());
    if(pts[0].first == p) cout << p << " " << (-pts[0].second)-1 << endl;
    else cout << pts[0].first+1 << " " << (-pts[0].second) << endl;

    return 0;
}
