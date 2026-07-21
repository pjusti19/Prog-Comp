#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

int lcs_size[3010][3010];
string s, t;
string lcs = "";


int encontrar_tamanho(int i , int j){
    if(i == s.size() or j == t.size()) return 0;
    int& p = lcs_size[i][j];
    if(s[i] == t[j]) return p = encontrar_tamanho(i++, j++) + 1;
    return p = max(encontrar_tamanho(i, j++), encontrar_tamanho(i++, j)) + 1;
}

void recuperar(int i, int j){
    if(i >= s.size() or j >= t.size()) return;
    if(s[i] == t[j]){
        lcs.push_back(s[i]);
        return recuperar(i+1, j+1);
    }
    else if(lcs_size[i+1][j] > lcs_size[i][j+1]) return recuperar(i+1, j);
    return recuperar(i, j+1);
}

int main()
{ _

    cin >> s >> t;
    
    encontrar_tamanho(0, 0);

    recuperar(0, 0);

    cout << lcs << endl;

    return 0;

}