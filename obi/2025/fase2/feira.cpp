#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long estoque, num_tipos;
    cin >> estoque >> num_tipos;
    vector<pair<long long, int>> tipos(estoque, {0, 0});
    vector<long long> precos(estoque);
    for (int i = 0; i < estoque; i++)
    {
        long long tipo;
        cin >> tipo;
        tipos[i].first = tipo;
        tipos[i].second++;
    }
    for (long long &p : precos) cin >> p;
    long long num_clientes;
    cin >> num_clientes;
    vector<long long> clientes(num_clientes);
    for (long long &c : clientes) cin >> c;





    return 0;
}

//priority_queue<int, vector<int>, greater<int>>
//set<pair<int,int>> // (preço, tipo)