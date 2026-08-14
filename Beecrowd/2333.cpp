#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int INF = 0x3f3f3f3f;

int main(){ _
    int n; cin >> n;
    vector<int> fatias(n);
    int total = 0;
    for(int&f:fatias) {cin >>f; total += f;}
    int maior = -INF, menor = INF, umn = INF, umx = -INF;
    for(int i = 0; i < n; i++){
        umx = max(fatias[i], fatias[i]+umx);
        umn = min(fatias[i], fatias[i]+umn);
        maior = max(maior, umx);
        menor = min(menor, umn);
    }
    cout << max({maior, total-menor, 0}) << endl;
    return 0;
}