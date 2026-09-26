#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    if(n == 0) cout << "*";
    else if(n >= 5) {cout << "IIIII"; n -=5;}
    else {for(int i = 0; i < n%5; i++) {cout << "I";} n-= (n%5);}
    cout << endl;
    if(n == 0) cout << "*";
    else if (n == 5) cout << "IIIII";
    else for(int i = 0; i < n%5; i++) {cout << "I";}
    cout << endl;
    return 0;
}
