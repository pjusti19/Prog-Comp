#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

string soma_um(string s){
    for(int t = s.length()-1; t >= 0; t--){
        if(s[t] != '9'){ s[t] +=1; return s;}
        s[t] = '0';
    }
    string r = "1";
    r+=s;
    return r;
}

int main(){ _ 
    int n; cin >> n;
    vector<int> digitos(n);
    for(int&d:digitos) cin >> d;
    string primeiro, ultimo;
    for(int i = 0; i < n ; i++){
        primeiro = "";
        ultimo = "";
        for(int j = i, k = 0; k <= i; j--, k++) {
            primeiro += ('0' + digitos[k]); 
            ultimo += ('0' + 9);
        }
        string anterior = primeiro;
        int tamanho = i+1;
        bool eh_valido = true;
        if(2*tamanho > n) break;
        for(int j = tamanho; j < n;){
            string atual = "";
            if(anterior == ultimo) {ultimo += ('0'+9); tamanho++;}
            for(int cont = 0, pot = tamanho-1; cont < tamanho; cont++, pot--) atual+= ('0'+digitos[j+cont]);
            if(atual != soma_um(anterior)) {eh_valido = false;break;}
            else j+= tamanho;
            anterior = atual;
        }
        if(eh_valido) {cout << primeiro << endl; return 0;}
    }
    for(int&d:digitos) cout << d;
    cout << endl;

    return 0;
}
