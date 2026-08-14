#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int p; cin >> p;
    for(int i = 0; i < p; i++){
       ll lim, min, max; cin >> lim >> min >> max;
       ll c = 0, prefix = 0;
       for(ll j = min; j <= max; j++){
        prefix += j;
        c++;
        if(prefix >= lim) break; 
       }
       cout << c << endl;
    }
    return 0;
}
