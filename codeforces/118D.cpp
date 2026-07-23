#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int MOD = 1e8;


int f, h, max_f, max_h;
int memo[110][110][2][11];

int dp(int i, int j, int ultimo, int cont){
    if(i >= f and j >= h) return 1;
    int& p = memo[i][j][ultimo][cont];
    if(p != -1) return p;
    p = 0;
    if(ultimo == 0){
        if(i < f and cont < max_f)
            p = (p + dp(i+1, j, 0, cont+1)) % MOD;
        if(j < h)
            p = (p + dp(i, j+1, 1, 1)) % MOD; 
    }
    else{
        if(j < h and cont < max_h)
            p = (p + dp(i, j+1, 1, cont+1)) % MOD;
        if(i < f)
            p = (p + dp(i+1, j, 0, 1)) % MOD; 
    }
    return p;
}

int main(){_
    cin >> f >> h >> max_f >> max_h;
    memset(memo, -1, sizeof memo);
    cout << (dp(1, 0, 0, 1) + dp(0, 1, 1, 1))% MOD << endl;
    return 0;
}

