#include <bits/stdc++.h>
using namespace std;

int main()
{

    char resultado;
    int pontuacao = 0;

    for (int i = 0; i < 6; i++)
    {
        cin >> resultado;
        if (resultado == 'V')
            pontuacao++;
    }

    if(pontuacao >= 5) cout << "1";
    else if(pontuacao >= 3) cout << "2";
    else if(pontuacao >= 1) cout << "3";
    else cout << "-1";

    return 0;
}