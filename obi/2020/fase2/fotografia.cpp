#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a, l, n;
    cin >> a >> l >> n;
    vector<pair<int,int>> molduras(n);
    for(auto &m : molduras) cin >> m.first >> m.second;
    int menor_folga = INT_MAX;
    int melhor_moldura = -1;
    for(int i = 0; i < n; i++){
        if((molduras[i].first >= a && molduras[i].second >= l) 
        || (molduras[i].first >= l && molduras[i].second >= a)){
            int folga = (molduras[i].first * molduras[i].second) - a * l;
            if(folga < menor_folga){
                menor_folga = folga;
                melhor_moldura = i+1;
            }
        }
    }
    cout << melhor_moldura << "\n";
    return 0;

}