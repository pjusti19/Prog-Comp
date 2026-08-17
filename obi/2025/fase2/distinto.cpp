//#include <bits/stdc++.h>
#include <iostream> 
#include <algorithm>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int p; cin >> p;
    for(int i = 0; i < p; i++){
       ll lim, min, max, an; cin >> lim >> min >> max;
       ll x1 = (1+std::sqrt(1+4*(min*min-min+2*lim)))/-2;
       ll x2 = (1-std::sqrt(1+4*(min*min-min+2*lim)))/-2;
       an = std::max(x1,x2);
       if(((an-min+1)*(an+min))/2 < lim) an++;
       if(an > max) an = max;
       cout << an - min + 1 << endl;
    }
    return 0;
}