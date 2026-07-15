#include <bits/stdc++.h>

using namespace std;

stack<int> st;

void dfs(int o, vector<vector<int>> &tuneis, vector<bool> &visited){

    visited[o] = true;

    for(auto &t : tuneis[o])
        if(visited[t] != true)
            dfs(t, tuneis, visited);

    st.push(o);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int s, t, p;
    cin >> s >> t >> p;
    vector<int> alturas(s);
    vector<vector<int>> tuneis(s+1);
    vector<bool> visited(s+1);
    for(auto &a : alturas) cin >> a;

    for(int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        if(alturas[a-1] > alturas[b-1]) tuneis[a].push_back(b);
        else if(alturas[a-1] < alturas[b-1]) tuneis[b].push_back(a);
    }
    dfs(p, tuneis, visited);
    vector<int> dist(s+1, -1);
    dist[p] = 0;
    while(!st.empty()){
        int curr = st.top();
        for(auto t: tuneis[curr])
            dist[t] = max(dist[t], dist[curr]+1);
        st.pop();
    }
    int maior = 0;
    for(auto d : dist){
        maior = max(d, maior);
    }
    cout << maior << "\n";
    return 0;
}