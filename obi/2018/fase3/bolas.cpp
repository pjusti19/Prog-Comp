#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    vector<int> bolas(8);
    vector<int> count (10,0);
    for(int&b:bolas) {cin >> b; count[b]++;}
    for(int&c:count) if(c >= 5) {cout << "N" << endl; return 0;}
    cout << "S" << endl;
    return 0;
}