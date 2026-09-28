#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> digitos(n);
    for(int&d:digitos) cin >> d;
    int p = -1;
    if(digitos[n-1] > 5){
        for(int i = 0; i < n; i++) if(digitos[i] == 0 or digitos[i] == 5) {p = i; break;} 
    }else{
        for(int i = 0; i < n; i++) if(digitos[i] == 0) {p = i; break;} 
        if(p == -1) for(int i = n-1; i >=0; i--) if(digitos[i] == 5) {p = i; break;}
    } 
    if(p == -1) {cout << -1 << endl; return 0;}
    swap(digitos[n-1], digitos[p]);
    for(int i = 0; i < n; i++){
        if(i == n-1) cout << digitos[i] << endl;
        else cout << digitos[i] << " ";
    }
    return 0;
}
