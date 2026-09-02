#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;
vector<int> teclas;
int seg[4*MAX];
vector<int> lazy(4*MAX, 0);
vector<unordered_map<int,int>> freq;

int build(int p, int l, int r){
    if(l == r) {freq[p][teclas[l]] = 1; return seg[p] = teclas[l];}
    int m = (l+r)/2;
    int u = build(2*p, l, m);
    int v = build(2*p+1, m+1, r);
    freq[p][u] = freq[2*p][u]+freq[2*p+1][u];
    freq[p][v] = freq[2*p][v]+freq[2*p+1][v];
    return seg[p] = freq[p][u]> freq[p][v]? u : v;
}

int update(int a, int b, int x, int p, int l, int r){
    if(a > r or b < l) return seg[p]; 
    if(l == r) {
        freq[p][teclas[l]]-=1;
        teclas[l] = (teclas[l] + x) % 9;
        freq[p][teclas[l]]+=1;
        return seg[p] = teclas[l];
    }
    int m = (l+r)/2;
    int u = update(a, b, x, 2*p, l, m);
    int v = update(a, b, x , 2*p+1, m+1, r);
    freq[p][u] = freq[2*p][u]+freq[2*p+1][u];
    freq[p][v] = freq[2*p][v]+freq[2*p+1][v];
    return seg[p] = freq[p][u]> freq[p][v]? u : v;
}

int query(int a, int b, int p, int l, int r){
    if(a <= l and b >= r) return seg[p];
    if(a > r or b < l) return -INF;
    int m = (l+r)/2;
    int u = query(a, b, 2*p, l, m);
    int v = query(a, b, 2*p+1, m+1, r);
    if(freq[p][u] == freq[p][v]) return max(u,v);
    return freq[p][u]> freq[p][v]? u : v;
}

int main(){ _ 
    int n, q; cin >> n >> q;
    teclas = vector<int> (n, 1);
    freq = vector<unordered_map<int,int>>(4*MAX);
    build(1, 0, n-1);
    while(q--){
        int a, b; cin >> a >> b;
        int mf = query(a, b, 1, 0, n-1);
        update(a, b, mf, 1 , 0, n-1);
    }
    for(int i = 0; i < n-1; i++) cout << teclas[i] << " " << endl;
    cout << teclas[n-1] << endl;

    return 0;
}
