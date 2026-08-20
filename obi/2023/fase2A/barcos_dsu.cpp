#include <iostream>
#include <queue>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> id, sz, ans;
vector<vector<pair<int,int>>> qs;


int find(int p) { return id[p] = (id[p] == p ? p: find(id[p]));}

void une(int p, int q, int peso){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    for(auto& [u, idx]: qs[p]){
        if(ans[idx] == -1 and find(u) == q) {ans[idx] = peso;}
        else if(ans[idx] == -1) qs[q].push_back({u, idx});
    }
    qs[p].clear();
    id[p] = q; sz[q] += sz[p];
}

int main(){ _ 
    int n, b; cin >> n >> b;
    priority_queue<tuple<int, int,int>> pq;
    id = vector<int>(n+1), sz= vector<int>(n+1,1);
    iota(id.begin(), id.end(), 0);
    for(int i = 0; i < b; i++){
        ll p; int a, b; cin >> a >> b >> p;
        pq.push({p, a, b});
    }
    int c; cin >> c;
    qs = vector<vector<pair<int,int>>> (n+1);
    for(int i = 0; i < c; i++){
        int x, y; cin >> x >> y;
        qs[x].push_back({y,i});
        qs[y].push_back({x,i});
    }
    ans = vector<int>(c, -1);
    while(!pq.empty()){
        auto [p, a, b] = pq.top(); pq.pop();
        une(a, b, p);
    }
    for(auto&a:ans) cout << a << endl;

    return 0;
}