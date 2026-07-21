#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

int lcs_size[3010][3010];
string s, t;
string lcs = "";

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
    for(int i = s.size()-1; i >= 0; i--){
        for(int j = t.size()-1; j >= 0; j--){
            if(s[i] == t[j]) lcs_size[i][j] = lcs_size[i+1][j+1] + 1;
            else lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
        }
    }

    recuperar(0, 0);

    cout << lcs << endl;

    return 0;

}