//#include <bits/stdc++.h>
#include <iostream> 
#include <algorithm>
#include <numeric>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> id, sz;
vector<ll> poder;
vector<vector<int>> cand;

int find(int p) { return id[p] = (id[p] == p? p : find(id[p]));}

void une(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q; sz[q]+=sz[p];
    poder[q] += poder[p];
    if(cand[p].size() > cand[q].size()) swap(cand[p], cand[q]);
    for(int&c:cand[p]) cand[q].push_back(c);
    cand[p].clear();
}

int main(){ _
    int n, m; cin >> n >> m;
    vector<tuple<ll,int,int>> herois;
    poder = vector<ll> (n*m+1), cand = vector<vector<int>> (n*m+1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll x; cin >> x;
            int k = i * m + j;
            poder[k] = x;
            cand[k].push_back(k);
            herois.push_back({x, i, j});
        }
    }
    sort(herois.begin(), herois.end());
    id = vector<int> (n*m), sz = vector<int> (n*m, 1);
    iota(id.begin(), id.end(), 0);
    vector<vector<bool>> ativos(n, vector<bool>(m, false));
    vector<vector<ll>> ans(n, vector<ll>(m, 0));
    int dx[4] = {1, 0 , -1, 0}, dy[4] = {0, 1, 0, -1};
    for(auto [p, l, c] : herois){
        ativos[l][c] = true;
        int atual = l * m + c;
        for(int i = 0; i < 4; i++){
            int n_l = l + dy[i], n_c = c + dx[i];
            int n_k = n_l*m+n_c;
            if(n_l < 0 or n_l >= n or n_c < 0 or n_c >= m or !ativos[n_l][n_c]) continue;
            int viz = find(n_k);
            if(p > poder[viz]){
                for(int&can:cand[viz]) ans[can/m][can%m] = poder[viz];
                cand[viz].clear();
            } 
            une(atual, n_k);
        }
    }
    for(int i = 0; i < n*m; i++){
        int r = find(i);
        for(int&can:cand[r])ans[can/m][can%m] = poder[r];
        cand[r].clear();
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == m-1) cout << ans[i][j] << endl;
            else cout << ans[i][j] << " ";
        }
    }
    return 0;
}