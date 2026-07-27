#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

int main(){_ 

    int n; cin >> n;
    vector<double> precos(n);
    for(int i = 0; i < n; i++){
        double p, g;
        cin >> p >> g;
        precos[i] = p/g;
    }
    double menor = INT_MAX;
    for(auto p:precos) menor = min(p, menor);
    printf("%.2f\n", menor*1000);

    return 0;
}