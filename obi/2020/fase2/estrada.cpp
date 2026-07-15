#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t, n;
    cin >> t >> n;
    vector<int> distancias(n);
    for(auto &d : distancias) cin >> d;
    sort(distancias.begin(), distancias.end());
    vector<double> vizinhancas(n);
    double esquerda = distancias[0];
    for(int i = 0; i < n; i++){
        double direita;
        if(i == n-1) direita = t - distancias[i];
        else direita = (distancias[i+1] - distancias[i]) / 2.0;
        vizinhancas[i] = esquerda + direita;
        esquerda = direita;
    }
    sort(vizinhancas.begin(), vizinhancas.end());
    printf("%.2f\n", vizinhancas[0]);
    return 0;
}