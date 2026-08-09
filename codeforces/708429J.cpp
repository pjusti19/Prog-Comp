#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){ _ 
    double a, b, c; cin >> a >> b >> c;
    double mx_r = a+b+c;
    double mn_r;
    if(a < b+c and a > abs(b-c)) mn_r = 0.0;
    else{
        mn_r = abs(a+b-c);
        for(int i = abs(b-c); i <= b+c; i++)
            mn_r = min(mn_r, abs(a-i));
    }
    //printf("%.2f\n", mn_r);
    printf("%.15f\n", (3.14159265359 *(mx_r*mx_r)) - (3.14159265359 *(mn_r*mn_r)));
    return 0;
}