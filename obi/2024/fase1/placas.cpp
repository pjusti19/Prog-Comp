#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string placa;
    cin >> placa;

    int tamanho_placa = placa.length();

    if(tamanho_placa == 8){
        for(int i = 0; i < 3; i++){
            if(placa[i] < 'A' || placa[i] > 'Z'){
                cout << 0 << "\n";
                return 0;
            }
        }
        if(placa[3] != '-') { 
            cout << 0 << "\n";
                return 0;
        }
        for(int i = 4; i < tamanho_placa; i++){
            if(placa[i] < '0' || placa[i] > '9'){
                cout << 0 << "\n";
                return 0;
            }
        }
        cout << 1 << "\n";
    }
    else if(tamanho_placa == 7){
        for(int i = 0; i < 3; i++){
            if(placa[i] < 'A' || placa[i] > 'Z'){
                cout << 0 << "\n";
                return 0;
            }
        }
        if(placa[3] < '0' || placa[3] > '9'){
                cout << 0 << "\n";
                return 0;
            }
        if(placa[4] < 'A' || placa[3] > 'Z'){
                cout << 0 << "\n";
                return 0;
            }
        for(int i = 5; i < tamanho_placa; i++){
            if(placa[i] < '0' || placa[i] > '9'){
                cout << 0 << "\n";
                return 0;
            }
        }
        cout << 2 << "\n";
    }
    else  cout << 0 << "\n";

    return 0;
}