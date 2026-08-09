#include <bits/stdc++.h>
 
using namespace std;
 
#define BINGOS 3
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){ _
    int a, b; cin >> a >> b;
    if(a > b) cout << "El Cacto";
    else if(b > a)  cout << "WA";
    else cout << "Empate";
    return 0;
}