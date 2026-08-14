#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int hp, x, y; cin >> hp >> x >> y;
        while((hp-floor(hp/2))>10 and x){
            hp = floor(hp/2) + 10;
            x--;
        }
        while(y and hp > 0){
            hp -= 10;
            y--;
        }
        if(hp <= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
