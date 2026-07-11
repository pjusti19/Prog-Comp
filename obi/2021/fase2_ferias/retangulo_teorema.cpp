#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

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
    if (perimetro % 2)
    {
        cout << "N\n";
        return 0;
    }
    vector<pair<int, int>> opostos;
    for (int i = 0; i < num_pontos; i++)
    {
        int alvo = perimetro / 2 + distancias_acumuladas[i];
        if (alvo > perimetro)
            alvo %= perimetro;
        auto it = lower_bound(distancias_acumuladas.begin(), distancias_acumuladas.end(), alvo);
        int indice = it - distancias_acumuladas.begin();
        if (it != distancias_acumuladas.end() && *it == alvo)
        {
            if (opostos.empty())
                opostos.push_back({i, indice});
            else if (opostos.back().first != indice || opostos.back().second != i)
            {
                cout << "S" << "\n";
                return 0;
            }
        }
    }
    cout << "N" << "\n";

    return 0;
}