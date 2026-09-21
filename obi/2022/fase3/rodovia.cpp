#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;

int find(int p){return id[p] = (id[p] == p? p: find(id[p]));}

void une(int p , int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
}

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> cont(n+1, 0);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cont[x]++;
        cont[y]++;
    }
    id = vector<int> (n+1);
    sz = vector<int> (n+1, 1);
    iota(id.begin(), id.end(),0);
    for(int i = 1; i < n+1; i++)
        for(int&a:adj[i]) une(a, i);

    for(int i = 1; i < n+1; i++){
        if(cont[i] < sz[find(i)]-1){
            vector<bool> ps(n+1, false);
            for(int&a:adj[i]) ps[a] = true;
            for(int j = 1; j < n+1; j++) if(!ps[j] and j != i and find(i) == find(j)) {
                cout << i << " " << j << endl; 
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
