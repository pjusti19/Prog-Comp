#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n,m; cin >> n >> m;
    vector<int> alturas(n);
    for(auto& a:alturas) cin >> a;
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int diff = m - alturas[i];
        ans += abs(diff);
        alturas[i+1] += diff;
    }
    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// #define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n'

// typedef long long ll;

// const int INF = 0x3f3f3f3f;
// const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// int main(){ _ 
//     int n,m; cin >> n >> m;
//     vector<int> alturas(n);
//     for(auto& a:alturas) cin >> a;
//     int ans = 0;
//     for(int l = 0, r = n-1; l < r; l++, r--){
//         if(alturas[l] != m){
//             if(alturas[l] > m) {
//                 alturas[l+1] -= alturas[l] - m;
//                 ans += abs(alturas[l] - m);
//             }
//             else{
//                 alturas[l+1] += m - alturas[l];
//                 ans += m - alturas[l];
//             }     
//         }
//         if(alturas[r] != m){
//            if(alturas[r] > m) {
//                 alturas[r-1] -= alturas[r] - m;
//                 ans += abs(alturas[r] - m);
//             }
//             else{
//                 alturas[r-1] += m - alturas[r];
//                 ans += m - alturas[r];
//             }  
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

