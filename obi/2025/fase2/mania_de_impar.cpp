#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mesa(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mesa[i][j];

    int melhor = INT_MAX;
    vector<vector<int>> melhorMesa;

    for (int k = 0; k < 2; k++)
    {
        vector<vector<int>> temp = mesa;
        int proxEhImpar = k;
        int custo = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int resto = temp[i][j] % 2;

                if ((resto == 0 && proxEhImpar == 1) ||
                    (resto == 1 && proxEhImpar == 0))
                {
                    temp[i][j]++;
                    custo++;
                }

                proxEhImpar = !proxEhImpar;
            }
        }

        if (custo < melhor)
        {
            melhor = custo;
            melhorMesa = temp;
        }
    }

    cout << melhor << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << melhorMesa[i][j];
            if (j != m - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}