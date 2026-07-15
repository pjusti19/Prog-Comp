#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int s, t, p;
    cin >> s >> t >> p;
    vector<int> alturas(s);
    for(auto &a : alturas) cin >> a;
    vector<vector<int>> tuneis(s+1);
    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        if(alturas[a-1] > alturas[b-1]) tuneis[a].push_back(b);
        else if(alturas[a-1] < alturas[b-1]) tuneis[b].push_back(a);
    }
    stack<int> caminho;
    vector<int> distancias(s+1, 0);
    int maior = 0;

    caminho.push(p);
    while(!caminho.empty()){
        int sala = caminho.top();
        caminho.pop();
        for(auto &t : tuneis[sala]){
            if(distancias[t] > distancias[sala]+1) continue;
            caminho.push(t);
            distancias[t] = distancias[sala]+1;
            maior = max(distancias[t], maior);
        }
    }

    cout << maior << "\n";

    return 0;

}