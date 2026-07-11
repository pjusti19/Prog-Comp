#include <bits/stdc++.h>

using namespace std;

inline int idOf(const string& s) {
    return (s[0] - 'a') * 26 + (s[1] - 'a');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l, c;
    cin >> l >> c;
    const int NV = 26 * 26;
    vector<unordered_map<int, int>> var_linhas(l), var_colunas(c);
    vector<int> vars(NV, 0);
    vector<char> existe(NV, 0);
    vector<set<int>> linhas_da_var(NV), colunas_da_var(NV);
    vector<int> soma_linhas(l), soma_colunas(c);
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            if (j != c)
            {
                string var;
                cin >> var;
                int id = idOf(var);
                existe[id] = 1;
                linhas_da_var[id].insert(i);
                colunas_da_var[id].insert(j);
                var_linhas[i][id] += 1;
                var_colunas[j][id] += 1;
            }
            else
            {
                int soma;
                cin >> soma;
                soma_linhas[i] = soma;
            }
        }
    }
    for (int i = 0; i < c; i++)
        cin >> soma_colunas[i];

    queue<pair<char, int>> q;

    for (int i = 0; i < l; i++)
        if (var_linhas[i].size() == 1)
            q.push({'l', i});

    for (int i = 0; i < c; i++)
        if (var_colunas[i].size() == 1)
            q.push({'c', i});

    while (!q.empty())
    {
        auto processado = q.front();
        q.pop();
        int indice = processado.second;
        if (processado.first == 'l')
        {
            if (var_linhas[indice].size() != 1) continue;
            int var = var_linhas[indice].begin()->first;
            vars[var] = soma_linhas[indice] / var_linhas[indice].begin()->second;
            for (auto x : linhas_da_var[var])
            {
                soma_linhas[x] -= vars[var] * var_linhas[x][var];
                var_linhas[x].erase(var);
                if (var_linhas[x].size() == 1)
                    q.push({'l', x});
            }
            for (auto x : colunas_da_var[var])
            {
                soma_colunas[x] -= vars[var] * var_colunas[x][var];
                var_colunas[x].erase(var);
                if (var_colunas[x].size() == 1)
                    q.push({'c', x});
            }
        }
        else
        {
            if (var_colunas[indice].size() != 1) continue;
            int var = var_colunas[indice].begin()->first;
            vars[var] = soma_colunas[indice] / var_colunas[indice].begin()->second;
            for (auto x : colunas_da_var[var])
            {
                soma_colunas[x] -= vars[var] * var_colunas[x][var];
                var_colunas[x].erase(var);
                if (var_colunas[x].size() == 1)
                    q.push({'c', x});
            }
            for (auto x : linhas_da_var[var])
            {
                soma_linhas[x] -= vars[var] * var_linhas[x][var];
                var_linhas[x].erase(var);
                if (var_linhas[x].size() == 1)
                    q.push({'l', x});
            }
        }
    }

    for (int id = 0; id < NV; id++)
        if (existe[id])
            cout << char('a' + id / 26) << char('a' + id % 26) << " " << vars[id] << "\n";

    return 0;
}