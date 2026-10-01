#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

vector<int> id, sz;

int find(int p){ return id[p] = (id[p] == p? p : find(id[p])); }

void uni(int p, int q){
    p = find(p), q = find(q);
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q] += sz[p];
}

int main(){ _
    int n; cin >> n;
    id = vector<int> (n), sz = vector<int> (n,1);
    iota(id.begin(), id.end(), 0);
    vector<pair<int,int>> alt(n);
    for(int i = 0; i < n; i++){
        int h; cin >> h;
        alt[i] = {h, i};
    }
    sort(alt.begin(), alt.end());
    int ans = -1, c = 0;
    vector<bool> cortados(n, false);
    for(int i = n-1; i >=0 ; i--){
        auto [h, idx] = alt[i];
        cortados[idx] = true;
        c++;
        if(idx-1 >= 0 and cortados[idx-1]) {uni(idx, idx-1); c--;}
        if(idx+1 < n and cortados[idx+1]) {uni(idx, idx+1); c--;}
        ans = max(ans, c);
    }
    cout << ans + 1 << endl;
    return 0;
}