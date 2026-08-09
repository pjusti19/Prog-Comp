#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int main(){ _
    int n; cin >> n;
    vector<vector<bool>> jogo(5, vector<bool>(5, false));
    jogo[0][1] = jogo[0][2] = jogo[1][2] = jogo[1][3] = jogo[2][3] = jogo[2][4] = jogo[3][0] = jogo[3][4] = jogo[4][0] = jogo[4][1] = true;
    int d = 0, x = 0;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        if(jogo[a][b]) d++;
        else if(jogo[b][a]) x++;
    }
    if(d>x) cout << "dario";
    else cout << "xerxes";
    cout << endl;
    
    return 0;
}