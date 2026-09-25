#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> camelos(n);
    int total = 0;
    for(int&c:camelos) {cin >> c; total+=c;}
    total /= n;
    for(int&c:camelos) cout << total - c << endl;
    return 0;
}
