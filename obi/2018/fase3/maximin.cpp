#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n, l, r; cin >> n >> l >> r;
    vector<ll> nums(n);
    for(ll&n:nums) cin >> n;
    sort(nums.begin(), nums.end());
    ll ans = -LLINF;
    for(int i = 0; i < n; i++){
        if(nums[i] < l or nums[i] > r) continue;
        if(i-1 < 0) ans = max(ans, nums[i]-l);
        else if(nums[i-1] < l and nums[i] != l) ans = max(min(l-nums[i-1], nums[i]-l), ans);
        else if(i+1 >= n) ans = max(ans, r-nums[i]);
        else if(nums[i+1] > r and nums[i] != r) ans = max(min(nums[i+1]-r, r-nums[i]), ans);
        else{
            ll meio = nums[i]+(nums[i-1]-nums[i])/2;
            ans = max(ans, min(nums[i]-meio, meio-nums[i-1]));
        }
    }
    if(ans == -LLINF){
        int primeiro = lower_bound(nums.begin(), nums.end(), l)- nums.begin();
        primeiro == 0? primeiro = 0: primeiro-=1;
        int ultimo = lower_bound(nums.begin(), nums.end(), r)- nums.begin();
        for(ll i = l; i <= r; i++)
            ans = max(ans, min(i-nums[primeiro], nums[ultimo]-i));
    } // GAMBIARRISSIMA
    cout << ans << endl;
    return 0;
}