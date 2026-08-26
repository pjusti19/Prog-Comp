#include <iostream>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _ 
    int n; cin >> n;
    vector<ll> le, ld, pos;
    vector<int> sec (n+1); 
    int e = 0;
    for(int i = 1; i < n+1; i++){
        cin >> sec[i];
        if(sec[i] == 1){
            if(e != 0) ld.push_back(i);
            le.push_back(e);
            pos.push_back(i);
            e = i;
        }
    }
    ld.push_back(n+1);
    //for(int&l:le) cout << l << " ";
    ll ans  = 0;
    int q = le.size();
    for(int i = 0; i < q; i++){
        ans+= 1;
        ans += pos[i] - le[i] - 1;
        //cout << "le " << ans << endl;
        ans += ld[i] - pos[i] - 1;
       // cout << "ld " << ans << endl;
        if(pos[i] < n and pos[i] > 1) ans += (pos[i] - le[i] - 1) * (ld[i] - pos[i] - 1);
        //cout << "a " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}