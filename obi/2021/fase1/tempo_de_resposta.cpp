#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{

    int quant;
    int eventos[100][2];

    bool proximo_foi_t = true;
    char tipo_evento;
    int numero_evento;

    cin >> quant;

    loop(i, 0, quant)
    {
        cin >> tipo_evento;
        cin >> numero_evento;

        if (tipo_evento == 'T')
        {
            proximo_foi_t = true;
            loop(i, 0, 100)
            {
                if (eventos[i][0] == 'R')
                    eventos[i][1] += numero_evento;
            }
        }

        if (proximo_foi_t == false)
        {
            loop(i, 0, 100)
            {
                if (eventos[i][0] == 'R')
                    eventos[i][1]++;
            }
        }

        if (tipo_evento == 'R')
        {
            if (eventos[numero_evento - 1][0] != 'E')
                eventos[numero_evento - 1][1] = 0; // tempo
            eventos[numero_evento - 1][0] = 'R';
            proximo_foi_t = false;
        }
        else if (tipo_evento == 'E')
        {
            eventos[numero_evento - 1][0] = 'E';
            proximo_foi_t = false;
        }
    }

    loop(i, 0, 100)
    {
        if (eventos[i][0] == 'R')
            cout << i + 1 << " " << "-1" << "\n";
        else if (eventos[i][0] == 'E')
            cout << i + 1 << " " << eventos[i][1] << "\n";
    }

    return 0;
}