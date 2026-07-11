#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> jogo(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            string linha;
            cin >> linha;
            for (int j = 0; j < n; j++){
                if(linha[j] == '0') jogo[i][j] = 0;
                else                 jogo[i][j] = 1;
            }

        }
            

    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    vector<vector<int>> aux(n, vector<int>(n));
    for (int x = 0; x < q; x++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int vizinhos_vivos = 0;
                 for (int k = 0; k < 8; k++)
                    {
                        if (i + dy[k] < 0 || i + dy[k] >= n || j + dx[k] < 0 || j + dx[k] >= n)
                            continue;
                        if (jogo[i + dy[k]][j + dx[k]] == 1)
                            vizinhos_vivos++;
                        if (vizinhos_vivos > 3)
                            break;
                    }
                if (jogo[i][j] == 0)
                {
                    if (vizinhos_vivos == 3)
                        aux[i][j] = 1;
                    else
                        aux[i][j] = 0;
                }
                else
                {
                    if (vizinhos_vivos == 3 || vizinhos_vivos == 2)
                        aux[i][j] = 1;
                    else
                        aux[i][j] = 0;
                }
            }
        }
        jogo = aux;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << jogo[i][j];
        cout << "\n";
    }

    return 0;
}