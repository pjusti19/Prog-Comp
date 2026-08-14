#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

const int INF = 0x3f3f3f3f;

vector<int> alturas;
int n;

bool ok(int chute){
    if(chute == 1) return true;
    for(int i = chute-1; i <= n-chute; i++){
        if(alturas[i] < chute) continue;
        int e = i-1, d = i+1, h = chute-1;
        while(true){
            if(alturas[e] < h or alturas[d] < h) break;
            e--; d++; h--;
            if(d - i == chute) return true;
        }
    }
    return false;
}

int main(){ _
    int maior = -INF; cin >> n;
    alturas = vector<int> (n);
    for(int&a:alturas) {cin >> a; maior = max(maior, a);}
    int l = 0, r = maior+1;
    while(l < r){
        int m = (l+r+1)/2;
        if(ok(m)) l = m;
        else r = m-1;
    }
    cout << l << endl;

    return 0;
}