#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int num_brinquedos;
    cin >> num_brinquedos;
    vector<int> votos_brinquedo(num_brinquedos);
    int maior = -1;
    for(int &voto: votos_brinquedo){
        cin >> voto;
        maior = max(maior, voto);
    }   

    vector<int> primeira_linha(num_brinquedos);
    for(int i = 0; i < num_brinquedos; i++)
        primeira_linha[i] = maior - votos_brinquedo[i];

    for(int i = 0; i < maior; i++){
        for(int j = 0; j < num_brinquedos; j++){
            int resultado = 0;
            if(primeira_linha[j] <= i) resultado = 1;
            if(j == num_brinquedos-1)
                cout << resultado << "\n";
            else    
                cout << resultado << " ";
        }
    }
    return 0;
}