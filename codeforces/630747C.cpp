#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

int main(){ _ 
    ll w, n; cin >> w >> n;
    ll area = 0;
    for(int i = 0; i < n; i++){
        ll l_, w_; cin >> l_ >> w_;
        area += l_ * w_;
    }
    cout << area / w << endl;
}