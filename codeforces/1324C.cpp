#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string s; 
bool check(int chute){
    int n = s.length()-1;
    int cont = 0;
    while(cont < chute){
        if(s[n] == 'R') cont = 0;
        else cont++;
        n--;
        if(n == -1 and cont != chute) return true;
    }
    return false;
}

int main(){ _ 
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cin >> s;
        int l = 0, r = s.length()+1;
        while(l < r){
            int m = (l+r)/2;
            // cout << "primeiro" << endl;
            // cout << "l: " << l << " r: " << r << " m: " << m << endl;
            if(!check(m)) l = m+1;
            else r = m;
            // cout << "segundo" << endl;
            // cout << "l: " << l << " r: " << r << " m: " << m << endl;
        }
        cout << l << endl;
    }

    return 0;
}
