#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); 
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2*1e5;

vector<ll> nums;
ll seg[4*MAX];
ll lazy[4*MAX];

ll build(int p, int l, int r){
    if(l == r) return seg[p] = nums[l];
    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

void apply(int p, ll x){
    lazy[p] += x;
    seg[p] += x;
}

void push(int p, int l, int r){
    if(l == r or lazy[p] == 0) return;
    apply(2*p, lazy[p]);
    apply(2*p+1, lazy[p]);
    lazy[p] = 0;
}

ll update(int a, int b, ll x, int p, int l, int r){
    if(a > r or b < l) return seg[p];
    if(a <= l and b >= r){
        apply(p, x);
        return seg[p];
    }
    push(p, l, r);
    int m = (l+r)/2;
    return seg[p] = min(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
}

ll query(int a, int b, int p, int l, int r){
    if(a > r or b < l) return LLINF;
    if(a <= l and b >= r) return seg[p];
    push(p, l, r);
    int m = (l+r)/2;
    return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}
int main(){ _ 
    int n; scanf("%d", &n);
    nums = vector<ll>(n);
    for(ll&nu:nums) scanf("%lld", &nu);
    int m; scanf("%d", &m);
    char linha[100];
    fgets(linha, sizeof linha, stdin);
    build(1, 0, n-1);
    while(m--){
        fgets(linha, sizeof linha, stdin);
        int lf, rg, v;
        int quant = sscanf(linha, "%d %d %d", &lf, &rg, &v);
        if(quant == 3){
            if(rg < lf){
                update(lf, n-1, v, 1, 0, n-1);
                update(0, rg, v, 1, 0, n-1);
            }
            else update(lf, rg, v, 1, 0, n-1);
        }else{
            if(rg < lf) cout << min(query(0, rg, 1, 0, n-1), query(lf, n-1, 1, 0, n-1)) << endl;
            else cout << query(lf, rg, 1, 0, n-1) << endl;
        }
    }
    return 0;
}
