#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vector<int> nums(n);
    for(auto& num:nums) cin >> num;
    int ultimo = -INF, ans = -INF;
    for(int i = 0; i < n; i++){
        if(ultimo < 0) ultimo = nums[i];
        else {ultimo += nums[i]; ans = max(ans, ultimo);}
    }
    cout << ans << endl;
    return 0;
}
