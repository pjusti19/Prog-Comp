#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> id, sz;

int find(int p){ return id[p] = (id[p] == p? p : find(id[p]));}

void une(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
}

int main(){ _ 
    int n, m, k; cin >> n >> m >> k;
    vector<pair<int,int>> hidro, rodo;
    id = vector<int> (n+1), sz = vector<int> (n+1, 1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < m; i++){
        int a, b, t; cin >> a >> b >> t;
        if(t == 1) hidro.push_back({a,b});
        else rodo.push_back({a,b});
    }
    for(auto [a, b] : hidro){
        if(find(a) == find(b)) {cout << "N" << endl; return 0;}
        une(a, b);
    }
    for(auto [a, b] : rodo){
        if(find(a) == find(b)){
            k--;
            if(k < 0) {cout << "N" << endl; return 0;}
        }
        else une(a, b);
    } 
    cout << "S" << endl;
    return 0;
}