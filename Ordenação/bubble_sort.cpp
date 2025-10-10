#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

void bubble_sort(vector<int> &numeros, int tamanho)
{
    loop(i, 0, tamanho)
    {
        loop(j, 0, tamanho - i - 1)
        {
            if (numeros[j] > numeros[j + 1])
                swap(numeros[j], numeros[j + 1]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tamanho = 0;
    cin >> tamanho;
    vector<int> numeros(tamanho);

    loop(i, 0, tamanho)
            cin >>
        numeros[i];

    bubble_sort(numeros, tamanho);

    cout << "Vetor ordenado com Bubble Sort: [";

    loop(i, 0, tamanho - 1)
            cout
        << numeros[i] << ", ";

    cout << numeros[tamanho - 1] << "].";
}