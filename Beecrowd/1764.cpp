//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <numeric>


using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> sz, id;
int comps;

int find(int p){ return id[p] = ( id[p] == p? p : find(id[p]) );}

void une(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q; sz[q]+=sz[p];
    comps--;
}

int main(){ _ 
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0 and m == 0) return 0;
        id = vector<int>(n+1);
        iota(id.begin(), id.end(), 0);
        sz = vector<int> (n+1, 1);
        comps = n;
        priority_queue<tuple<int,int,int>> pq;
        for(int i = 0; i < m; i++){
            int p, a, b; cin >> a >> b >> p;
            pq.push({-p,a,b});
        }
        int ans = 0;
        while(comps > 1){
            auto [p, a , b] = pq.top(); pq.pop();
            p = -p;
            if(find(a) != find(b)) ans+=p;
            une(a, b);
        }
        cout << ans << endl;
    }
    return 0;
}
