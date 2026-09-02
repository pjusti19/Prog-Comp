#include <iostream>
#include <array>
#include <vector>

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
int freq[4*MAX][9];

void build(int p, int l, int r){
    if(l == r) {freq[p][teclas[l]] = 1; seg[p] = teclas[l]; return;}
    int m = (l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    for(int i = 0; i < 9; i++)
        freq[p][i] = freq[2*p][i]+freq[2*p+1][i];
    seg[p] = 0;
    for(int i = 1; i < 9; i++){
        if(freq[p][i] > freq[p][seg[p]] or (freq[p][i] == freq[p][seg[p]] and i > seg[p]))
            seg[p] = i;
    }
    return;
}

void apply(int p, int x){
    x %= 9;
    if(x == 0) return;

    lazy[p] = (lazy[p]+x) % 9;
    int novo[9];
    for(int i = 0; i < 9; i++) novo[(i+x)%9] = freq[p][i];
    for(int i = 0; i < 9; i++) freq[p][i] = novo[i];

    seg[p] = 0;
    for(int i = 1; i < 9; i++){
        if(freq[p][i] > freq[p][seg[p]] or (freq[p][i] == freq[p][seg[p]] and i > seg[p]))
            seg[p] = i;
    }
    return;
}

void push(int p, int l, int r){
    if(lazy[p] == 0 or l == r) return;

    int m = (l+r)/2;
    apply(2*p, lazy[p]);
    apply(2*p+1, lazy[p]);
    lazy[p] = 0;
}

void pull(int p){
    for(int i = 0; i < 9; i++) freq[p][i] = freq[2*p][i]+freq[2*p+1][i];
    seg[p] = 0;
    for(int i = 1; i < 9; i++){
        if(freq[p][i] > freq[p][seg[p]] or (freq[p][i] == freq[p][seg[p]] and i > seg[p]))
            seg[p] = i;
    }
    return;
}

void update(int a, int b, int x, int p, int l, int r){
    if(a > r or b < l) return; 
    if(a <= l and b >= r){
        apply(p, x);
        return;
    }
    push(p, l, r);
    int m = (l+r)/2;
    update(a, b, x, 2*p, l, m);
    update(a, b, x, 2*p+1, m+1, r);
    pull(p);
}

array<int,9> query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return {};
    if(a <= l and b >= r){
        array<int,9> ans;
        for(int i = 0; i < 9; i++) ans[i] = freq[p][i];
        return ans;
    }
    push(p, l, r);
    int m = (l+r)/2;
    auto esq = query(a, b, 2*p, l, m);
    auto dir = query(a, b, 2*p+1, m+1, r);
    for(int i = 0; i < 9; i++) esq[i] += dir[i];
    return esq;
}

void push_final(int p, int l, int r){
    if(l == r){
        teclas[l] = seg[p];
        return;
    }
    push(p, l, r);
    int m = (l+r)/2;
    push_final(2*p, l, m);
    push_final(2*p+1, m+1, r);
    return;
}

int main(){ _ 
    int n, q; cin >> n >> q;
    teclas = vector<int> (n, 1);
    build(1, 0, n-1);
    while(q--){
        int a, b; cin >> a >> b;
        auto resultado = query(a, b, 1, 0, n-1);
        int mf = 0;
        for(int i = 1; i < 9; i++) 
            if(resultado[i] >= resultado[mf]) mf = i;
        update(a, b, mf, 1 , 0, n-1);
    }
    push_final(1, 0, n-1);
    for(int i = 0; i < n; i++) cout << teclas[i] << endl;

    return 0;
}
