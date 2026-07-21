#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> tempo_deslocamento (n+1, vector<int>(n+1, 0));
    int num_caminhos = n * (n-1) / 2;
    for(int i = 0; i < num_caminhos; i++){
        int a, b, t;
        cin >> a >> b >> t;
        tempo_deslocamento[a][b] = t;
        tempo_deslocamento[b][a] = t;
    }
    vector<vector<ll>> memo (n+1, vector<ll>(n+1, INT_MAX));
    memo[1][0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            ll custo_atual = memo[i][j];
            memo[i+1][j] = min(custo_atual + tempo_deslocamento[i][i+1], memo[i+1][j]);

            ll custo_extra = (j == 0) ? tempo_deslocamento[1][i+1] : tempo_deslocamento[i+1][j];
            memo[i+1][i] = min((custo_extra + custo_atual), memo[i+1][i]);
        }
    }

    ll menor = INT_MAX;
    for(int i = 0; i < n; i++)
        menor = min(menor, memo[n][i]);

    cout << menor << endl;

    return 0;

}