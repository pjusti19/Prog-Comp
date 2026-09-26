#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int e1, e2, e3, x; cin >> e1 >> e2 >> e3 >> x;
    e2 - e1 <= x? cout << e2: cout << e3;
    cout << endl;
    return 0;
}
