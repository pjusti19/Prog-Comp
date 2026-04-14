#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> numeros;
    int quant;
    int numero;
    cin >> quant;

    for (int i = 0; i < quant; i++)
    {
        cin >> numero;
        if (numero != 0)
            numeros.push(numero);
        else
            numeros.pop();
    }

    int total = 0;
    int quant_numeros = (int)numeros.size();
    for (int i = 0; i < quant_numeros; i++)
    {
        total += numeros.top();
        numeros.pop();
    }
    cout << total;

    return 0;
}