#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e5;

typedef struct No{
    int menor;
    int maior;
    int diff;
}No;

vector<No> baldes;
No seg[4*MAX];

No build(int p, int l, int r){
    if(l == r) return seg[p] = baldes[l];
    int m = (l+r)/2;
    No no1 = build(2*p, l, m);
    No no2 = build(2*p+1, m+1, r);
    No atual; 
    atual.maior =  max(no1.maior, no2.maior); 
    atual.menor = min(no1.menor, no2.menor); 
    atual.diff = max({no1.diff, no2.diff, no1.maior - no2.menor, no2.maior - no1.menor});
    return seg[p] = atual; 
}

No update(int i, int x, int p, int l, int r){
    if(i < l or i > r) return seg[p];
    if(l == r){
        No novo;
        novo.maior = max(seg[p].maior, x);
        novo.menor = min(seg[p].menor, x);
        novo.diff = -INF;
        return seg[p] = novo;
    }
    int m = (l+r)/2;
    No no1 = update(i, x, 2*p, l, m);
    No no2 = update(i, x, 2*p+1, m+1, r);
    No atual; 
    atual.maior =  max(no1.maior, no2.maior); 
    atual.menor = min(no1.menor, no2.menor); 
    atual.diff = max({no1.diff, no2.diff, no1.maior - no2.menor, no2.maior - no1.menor});
    return seg[p] = atual;
}

No query(int a, int b, int p, int l, int r){
    if(a > r or b < l){
        No no; no.maior = -INF; no.menor = INF; no.diff = -INF;
        return no;
    }
    if(l >= a and r <= b) return seg[p];
    int m = (l+r)/2;
    No no1 = query(a, b, 2*p, l, m);
    No no2 = query(a, b, 2*p+1, m+1, r);
    No atual; 
    atual.maior =  max(no1.maior, no2.maior); 
    atual.menor = min(no1.menor, no2.menor); 
    atual.diff = max({no1.diff, no2.diff, no1.maior - no2.menor, no2.maior - no1.menor});
    return atual;
}

int main(){ _ 
    int n, m; cin >> n >> m;
    baldes = vector<No>(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        baldes[i].menor = baldes[i].maior = a;
        baldes[i].diff = -INF;
    }
    build(1, 0, n-1);
    while(m--){
        int t; cin >> t;
        if(t == 1){
            int p, i; cin >> p >> i;
            update(i-1, p, 1, 0, n-1);
        }
        else{
            int a, b; cin >> a >> b;
            cout << query(a-1, b-1, 1, 0, n-1).diff << endl;
        }
    }
    return 0;
}