#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<vector<int>> faces(n, vector<int>(7)) ;
    for(int i = 0; i < n; i++){
        int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
        faces[i][a] = f; faces[i][f] = a;
        faces[i][c] = e; faces[i][e] = c;
        faces[i][d] = b; faces[i][b] = d;
    }
    int ans = -INF;
    for(int i = 1; i < 7; i++){
        int chao = faces[0][i];
        vector<vector<bool>> disponiveis(n, vector<bool>(7, true));
        disponiveis[0][i] = disponiveis[0][chao] = false;
        for(int k = 1; k < n; k++){
            disponiveis[k][chao] = false;
            chao = faces[k][chao];
            disponiveis[k][chao] = false;
        }
        int cand = 0;
        for(int i = 0; i < n; i++){
            for(int j = 6; j >= 0; j--)
                if(disponiveis[i][j]) {cand += j; break;}
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
    return 0;
}
