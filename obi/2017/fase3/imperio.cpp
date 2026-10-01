#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    vector<int> parent(n+1, -1);
    vector<int> ordem;
    parent[1] = 0;
    q.push(1);
    ordem.push_back(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int&a:adj[u]){
            if(parent[a] != -1) continue;
            parent[a] = u;
            q.push(a);
            ordem.push_back(a);
        }
    }
    vector<int> tam_sub(n+1, 1);
    int ans = INF;
    for(int i = n-1; i >= 1; i--){
        tam_sub[parent[ordem[i]]] += tam_sub[ordem[i]];
        ans = min(ans, abs(n-2*tam_sub[ordem[i]]));
    } 
    cout << ans << endl;

    return 0;
}
