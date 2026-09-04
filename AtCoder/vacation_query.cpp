#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5*1e5+10;
string s; 

struct freq {
    pair<int,int> prefOne;
    pair<int,int> suffOne;
    pair<int,int> bestOne;

    pair<int,int> prefZero;
    pair<int,int> suffZero;
    pair<int,int> bestZero;
};

vector<freq> seg(4*MAX);
int lazy[4*MAX];

int len(pair<int,int>&p){ return p.first == -1? -1: p.second-p.first;}

void merge(freq& esq, freq& dir, freq& f){
    if(esq.prefOne.first != -1 and dir.prefOne.first != -1 and esq.prefOne.second == dir.prefOne.first-1) f.prefOne = {esq.prefOne.first, dir.prefOne.second};
    else f.prefOne = esq.prefOne;
    if(esq.prefZero.first != -1 and dir.prefZero.first != -1 and esq.prefZero.second == dir.prefZero.first-1) f.prefZero = {esq.prefZero.first, dir.prefZero.second};
    else f.prefZero = esq.prefZero;
    if(dir.suffOne.second != -1 and esq.suffOne.second != -1 and dir.suffOne.first == esq.suffOne.second+1 ) f.suffOne = {esq.suffOne.first, dir.suffOne.second};
    else f.suffOne = dir.suffOne;
     if(dir.suffZero.second != -1 and esq.suffZero.second != -1 and dir.suffZero.first == esq.suffZero.second+1 ) f.suffZero = {esq.suffZero.first, dir.suffZero.second};
    else f.suffZero = dir.suffZero;
    pair<int,int> candOne = {-1, -1};
    pair<int,int> candZero = {-1, -1};
    if(esq.suffOne.second != -1 and dir.prefOne.first != -1 and esq.suffOne.second == dir.prefOne.first-1) candOne =  {esq.suffOne.first, dir.prefOne.second};
    if(esq.suffZero.second != -1 and dir.prefZero.first != -1 and esq.suffZero.second == dir.prefZero.first-1) candZero = {esq.suffZero.first, dir.prefZero.second};
    if(len(esq.bestOne) > len(dir.bestOne)){
        if(len(esq.bestOne) > len(candOne)) f.bestOne = esq.bestOne;
        else f.bestOne = candOne;
    }
    else{
        if(len(dir.bestOne) > len(candOne)) f.bestOne = dir.bestOne;
        else f.bestOne = candOne;
    }
    if(len(esq.bestZero) > len(dir.bestZero)){
        if(len(esq.bestZero) > len(candZero)) f.bestZero = esq.bestZero;
        else f.bestZero = candZero;
    }
    else{
        if(len(dir.bestZero) > len(candZero)) f.bestZero = dir.bestZero;
        else f.bestZero = candZero;
    }
    return;
}

freq build(int p, int l, int r){
    if(l == r){
        if(s[l] == '1'){
            seg[p].prefOne = seg[p].suffOne = seg[p].bestOne = {l, r};
            seg[p].prefZero = seg[p].suffZero = seg[p].bestZero = {-1, -1};
        } 
        else{
            seg[p].prefOne = seg[p].suffOne = seg[p].bestOne = {-1, -1};
            seg[p].prefZero = seg[p].suffZero = seg[p].bestZero = {l, r};
        }
        return seg[p];
    }
    int m = (l+r)/2;
    freq esq = build(2*p, l, m);
    freq dir = build(2*p+1, m+1, r);
    merge(esq, dir, seg[p]);
    return seg[p];
}

void apply(int p, int x){
    x %= 2;
    if(x == 0) return;
    lazy[p] = (lazy[p]+x)%2;
    swap(seg[p].bestOne, seg[p].bestZero);
    swap(seg[p].prefOne, seg[p].prefZero);
    swap(seg[p].suffOne, seg[p].suffZero);
    return;
}

void push(int p, int l, int r){
    if(lazy[p] == 0 or l == r) return;
    apply(2*p, lazy[p]);
    apply(2*p+1, lazy[p]);
    lazy[p] = 0;
    return;
}

freq update(int a, int b, int x, int p, int l, int r){
    if(a > r or b < l) return seg[p];
    if(a <= l and b >= r){
        apply(p, x);
        return seg[p];
    }
    push(p, l, r);
    int m = (l+r)/2;
    freq esq = update(a, b, x, 2*p, l, m);
    freq dir = update(a, b, x, 2*p+1, m+1, r);
    merge(esq, dir, seg[p]);
    return seg[p];
}

freq query(int a, int b, int p, int l, int r){
    if(a <= l and b >= r) return seg[p];
    push(p, l, r);
    int m = (l+r)/2;
    if(b <= m) return query(a, b, 2*p, l, m);
    if(a > m) return query(a, b, 2*p+1, m+1, r);
    freq curr = freq({-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1});
    freq esq = query(a, b, 2*p, l, m);
    freq dir = query(a, b, 2*p+1, m+1, r);
    merge(esq, dir, curr);
    return curr;
}

int main(){ _ 
    int n, q; cin >> n >> q;
    cin >> s;
    build(1, 0, n-1);
    while(q--){
        int c, l, r; cin >> c >> l >> r;
        l--; r--;
        if(c == 1) update(l, r, 1, 1, 0, n-1);
        else{
          freq ans = query(l, r, 1, 0, n-1);
          if(ans.bestOne.first == -1) cout << 0 << endl;
          else cout << ans.bestOne.second - ans.bestOne.first + 1 << endl;
        } 
    }
    return 0;
}
