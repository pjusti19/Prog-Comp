#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int prioridade(char termo)
{
    if (termo == '+' || termo == '-')
        return 1;
    if (termo == '*' || termo == '/')
        return 2;
    if (termo == '^')
        return 3;
    return -1;
}

int main()
{

    int numero_expressoes = 0;
    cin >> numero_expressoes;

    while (numero_expressoes--)
    {
        stack<char> pilha_operadores;
        string expressao;
        cin >> expressao;
        for (char termo : expressao)
        {
            if (isalpha(termo))
                cout << termo;
            else if (isdigit(termo))
                cout << termo;
            else if (termo == '(')
                pilha_operadores.push(termo);
            else if (termo == ')')
            {
                while (!pilha_operadores.empty() && pilha_operadores.top() != '(')
                {
                    cout << pilha_operadores.top();
                    pilha_operadores.pop();
                }
                pilha_operadores.pop(); // tira o (
            }
            else
            {
                while (!pilha_operadores.empty() && ((prioridade(termo) < prioridade(pilha_operadores.top())) ||
                                                     (prioridade(termo) == prioridade(pilha_operadores.top()) && termo != '^')))
                {
                    cout << pilha_operadores.top();
                    pilha_operadores.pop();
                }
                pilha_operadores.push(termo);
            }
        }
        while (!pilha_operadores.empty())
        {
            cout << pilha_operadores.top();
            pilha_operadores.pop();
        }
        cout << '\n';
    }
}