#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<ll> reps(n);
        ll maior = -1;
        ll total = 0;
        for(auto& r: reps){
            cin >> r;
            total += r;
            maior = max(maior, r);
        } 
        if(total - maior >= maior-1) {cout << total << endl;}
        else {cout << 2*(total - maior)+1 << endl;}
    }
    return 0;
}