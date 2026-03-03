// Insertion Sort Offline
#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{

    int tamanho = 0;

    cin >> tamanho;

    vector<int> numeros(tamanho);

    loop(i, 0, tamanho)
    {
        cin >> numeros[i];
    }

    loop(i, 1, tamanho)
    {
        int chave = numeros[i];
        int j = i - 1;
        while ((j >= 0) && (numeros[j] > chave))
        {
            numeros[j + 1] = numeros[j];
            j--;
        }
        numeros[j+1] = chave;
    }

    cout << "Vetor ordenado com Insertion Sort: [";

    loop(i, 0, tamanho - 1)
            cout
        << numeros[i] << ", ";

    cout << numeros[tamanho - 1] << "]";
}