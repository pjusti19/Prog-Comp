#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int a, b; cin >> a >> b;
    vector<bool> mesas (3, false);
    mesas[a%3] = true;
    if(mesas[b%3]) mesas[(b+1)%3] = true;
    else mesas[b%3] = true;
    for(int i = 0; i < 3; i++) if(!mesas[i]) cout << i << endl;
    return 0;
}
