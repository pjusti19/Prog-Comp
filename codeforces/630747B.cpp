#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, s;
vector<int> pts;

bool check(int chute){

    int cont = 1;
    int ultimo = pts[0];
    for(int i = 1; i < n; i++){
        if(pts[i] - ultimo >= chute) {cont++; ultimo = pts[i];}
        if(cont == s) return true;
    }
    return false;
}

int main(){ _ 
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pts.push_back(x);
    }
    int l = 0, r = pts[n-1] - pts[0];
    while(l < r){
        int m = l + (r - l + 1)/2;
        if(check(m)) l = m;
        else r = m-1;
    }
    cout << l << endl;

    return 0;
}

// procurando o último true;