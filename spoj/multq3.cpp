#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;

int lazy[4*MAX];
int freq[4*MAX][3];

int build(int p, int l, int r){
    if(l == r) {return freq[p][0] = 1;}
    int m = (l+r)/2;
    return freq[p][0] = build(2*p, l, m)+build(2*p+1, m+1, r);
}
void apply(int p, int x){
    x %= 3;
    if(x == 0) return;
    lazy[p] += x;
    int novo[3];
    for(int i = 0; i < 3; i++) novo[(i+x)%3] = freq[p][i];
    for(int i = 0; i < 3; i++) freq[p][i] = novo[i];
    return;
}

void push(int p, int l, int r){
    if(lazy[p] == 0 or l == r) return;
    apply(2*p, lazy[p]);
    apply(2*p+1, lazy[p]);
    lazy[p] = 0;
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
    for(int i = 0; i < 3; i++) freq[p][i] = freq[2*p][i] + freq[2*p+1][i];
    return;
}

int query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return 0;
    if(a <= l and b >= r) return freq[p][0];
    push(p, l, r);
    int m = (l+r)/2;
    return query(a, b, 2*p, l, m)+query(a, b, 2*p+1, m+1, r);
}

int main(){ _ 
    int n, q; cin >> n >> q;
    build(1, 0, n-1);
    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t == 0) update(a, b, 1, 1, 0, n-1);
        else cout << query(a, b, 1, 0, n-1) << endl;
    }
    return 0;
}
