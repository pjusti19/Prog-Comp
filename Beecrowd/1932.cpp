#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, c; 
    cin >> n >> c;
    vector<int> val(n);
    for(int&v:val) cin >> v;
    vector<int> comprei(n), vendi(n);
    comprei[0] = -val[0] - c;
    vendi[0] = 0;
    for(int i = 1; i < n; i++){
        vendi[i] = max(vendi[i-1], comprei[i-1] + val[i]);
        comprei[i] = max(comprei[i-1], vendi[i-1] - c - val[i]); 
    }
    cout << vendi[n-1] << endl;

    return 0;
}
