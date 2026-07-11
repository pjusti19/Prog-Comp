#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long n, m, k;
    unsigned long long p;
    string senha;
    cin >> n >> m >> k;
    cin >> senha;
    vector<string> dicas(m);
    for (auto &d : dicas)
    {
        string dica;
        cin >> dica;
        sort(dica.begin(), dica.end());
        d = dica;
    }
    cin >> p;
    unsigned long long hashtags_restantes = m;
    unsigned long long margem = 0;
    for (int i = 0; i < m; i++)
    {
        unsigned long long limite_anterior = margem;
        auto index = senha.find("#");
        unsigned long long base = 1;
        for (int e = 0; e < hashtags_restantes - 1; e++)
        {
            base *= k;
            if (base > 1000000000)
            {
                base = 1000000001;
                break;
            }
        }
        for (int j = 0; j < k; j++)
        {
            unsigned long long limite_caractere = base * (j + 1) + margem;
            if (p > limite_caractere)
                limite_anterior = limite_caractere;
            else
            {
                senha[index] = dicas[i][j];
                margem = limite_anterior;
                break;
            }
        }
        hashtags_restantes--;
    }
    cout << senha << "\n";

    return 0;
}