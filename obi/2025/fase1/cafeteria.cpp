#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int vol_minimo, vol_maximo, capacidade, tamanho_dose;
    cin >> vol_minimo >> vol_maximo >> capacidade >> tamanho_dose;

    int min_cafe = capacidade - vol_minimo;
    int max_cafe = capacidade - vol_maximo;
    int resto = min_cafe % tamanho_dose;

    if(resto == 0 || min_cafe - resto >= max_cafe)
        cout << 'S' << "\n";
    else
        cout << 'N' << "\n";

    return 0;
}