#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num_pontos;
    cin >> num_pontos;
    vector<int> distancias(num_pontos), distancias_acumuladas(num_pontos);
    for (int i = 0; i < num_pontos; i++)
    {
        cin >> distancias[i];
        if (i == 0)
            distancias_acumuladas[i] = distancias[i];
        else
            distancias_acumuladas[i] = distancias_acumuladas[i - 1] + distancias[i];
    }
    int perimetro = distancias_acumuladas[num_pontos - 1];
    if(perimetro % 2){ cout << "N\n"; return 0; }
    for (int i = 0; i < num_pontos; i++)
    {
        int alvo = perimetro / 2 + distancias_acumuladas[i];
        if(alvo > perimetro) alvo %= perimetro;
        auto it = lower_bound(distancias_acumuladas.begin(), distancias_acumuladas.end(), alvo);
        int indice = it - distancias_acumuladas.begin();
        if (it != distancias_acumuladas.end() && *it == alvo)
        {
            int limite_inferior = i + 1;
            int limite_superior = indice + 1;
            if (limite_inferior >= num_pontos)
                limite_inferior = 0;
            if (limite_superior >= num_pontos)
                limite_superior = 0;
            int dist_inf = distancias[limite_inferior];
            int dist_sup = distancias[limite_superior];
            while (limite_inferior != indice && limite_superior != i)
            {
                if (dist_inf == dist_sup)
                {
                    cout << "S" << "\n";
                    return 0;
                }
                else if (dist_inf > dist_sup)
                {
                    limite_superior++;
                    if (limite_superior >= num_pontos)
                        limite_superior = 0;
                    dist_sup += distancias[limite_superior];
                }
                else
                {
                    limite_inferior++;
                    if (limite_inferior >= num_pontos)
                        limite_inferior = 0;
                    dist_inf += distancias[limite_inferior];
                }
            }
        }
    }
    cout << "N" << "\n";

    return 0;
}