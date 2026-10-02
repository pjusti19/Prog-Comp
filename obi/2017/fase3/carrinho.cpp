#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int n; 
vector<double> cargas, posicoes;
double memo[1000];

double dp(int i){
    if(i == n) return 0.0;
    double& p = memo[i];
    if(p != -1) return p;
    p = 10000000000.00;
    for(int j = i + 1; j <= n; j++){
        double d = posicoes[j]-posicoes[i];
        p = min(p, d*d/cargas[i] + dp(j));
    }
    return p;
}

int main(){ _ 
    double d; cin >> n >> d;
    cargas = vector<double>(n);
    posicoes = vector<double>(n+1);
    for(int i = 0; i < n; i++){
        double p, c; cin >> p >> c;
        cargas[i] = c;
        posicoes[i] = p;
    }
    posicoes[n] = d;
    for(int i = 0; i < 1000; i++) memo[i] = -1;
    double ans = dp(0);
    printf("%.3f\n", ans);
    return 0;
}
