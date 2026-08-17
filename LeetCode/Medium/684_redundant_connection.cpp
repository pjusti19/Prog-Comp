#include <bits/stdc++.h>

class Solution {
public:
    vector<int> id, sz;

    int find(int p) {return id[p] = (id[p] == p? p: find(id[p]));}
    void une(int p, int q){
        p = find(p), q = find(q);
        if(sz[p] > sz[q]) swap(p, q);
        id[p] = q; sz[q] += sz[p];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans(2);
        id = vector<int> (edges.size()+1), sz = vector<int> (edges.size()+1, 1);
        iota(id.begin(), id.end(), 0);
        for(int i = 0; i < edges.size(); i++){
            int a, b;
            a = edges[i][0], b = edges[i][1];
            if(find(a) == find(b)){ ans[0] = a, ans[1] = b;}
            else une(a, b); 
        }
        return ans;
    }
};