#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct pedacos{
    int pre[10];
    int suf[10];
}pedacos;

int main(){ _ 
    int n; cin >> n;
    vector<string> senhas(n);
    for(string&s:senhas) cin >> s;
    vector<pedacos> ps(n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            string comp = senhas[j];
            if(comp == senhas[i]) {cout << comp << endl; return 0;}
            for(int l = 1; l < 10; l++){
                for(int k = l, w = 0; k < 10; k++, w++){
                    if(comp[k] != senhas[i][w]){ps[i].suf[10-l] = false; break;}
                    if(i == 3 and j == 0) cout << comp[k] << " " << senhas[i][w]  << " j " << j << endl;
                    ps[i].suf[10-l] = true;
                }
            }
            for(int l = 8; l >= 0; l--){
                for(int k = l, w = 9; k >= 0; k--, w--){
                    if(comp[k] != senhas[i][w]){ps[i].pre[l] = false; break;}
                    if(i == 3) cout << comp[k] << " " << senhas[i][w]  << " j " << j << endl;
                    ps[i].pre[l] = true;
                }
            }
            if(i == 3){
            for(int w = 0; w < 10; w++) cout << ps[3].pre[w] << " ";
            cout <<endl;
            for(int w = 0; w < 10; w++) cout << ps[3].suf[w] << " ";
            cout <<endl;}
            for(int k = 1; k < 9; k++)
                if(ps[i].pre[k] and ps[i].suf[10-k]) {cout << senhas[i] << k << endl; return 0;}
        }
    }
    cout << "ok" << endl;
    return 0;
}
