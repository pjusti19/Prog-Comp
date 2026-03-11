#include <iostream>

using namespace std;

int main(){

    int valor_soma, inicio, fim, menor, maior;
    cin >> valor_soma;
    cin >> inicio;
    cin >> fim;

    for(int i = inicio; i < fim+1; i++){
        int soma_iteracao = 0;
        int numero_atual = i;
        while(numero_atual != 0){
            soma_iteracao += numero_atual % 10;
            numero_atual /= 10;
        }
        if(soma_iteracao == valor_soma){
            menor = i;
            break;
        }
    }

    for(int i = fim; i > inicio-1; i--){
        int soma_iteracao = 0;
        int numero_atual = i;
        while(numero_atual != 0){
            soma_iteracao += numero_atual % 10;
            numero_atual /= 10;
        }
        if(soma_iteracao == valor_soma){
            maior = i;
            break;
        }
    }

    cout << menor << endl;
    cout << maior << endl;

}