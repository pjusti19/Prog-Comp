#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

string a, b;
int ops[2010][2010];

int operacoes(int i, int j){
    if (i == a.size()) return b.size() - j;
    if (j == b.size()) return a.size() - i;
    auto& p = ops[i][j];
    if(p != -1) return p;
    if(a[i] == b[j]) return p = operacoes(i+1, j+1);
    return p = min({operacoes(i+1, j), operacoes(i, j+1), operacoes(i+1, j+1)}) + 1;
}

int main(){_
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        memset(ops, -1, sizeof ops);
        cout << operacoes(0,0) << endl;
    }
    return 0;
}