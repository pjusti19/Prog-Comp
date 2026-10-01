#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> postes(n);
    for(int&p:postes) cin >> p;
    int sub, rep;
    sub = rep = 0;
    for(int&p:postes){
        if(p < 50) sub++;
        else if(p < 85) rep++;
    }
    cout << sub << " " << rep << endl;
    return 0;
}
