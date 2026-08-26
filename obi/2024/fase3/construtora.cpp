#include <iostream>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() { _ 
    int n; cin >> n;
    vector<int> alturas(n);
    vector<bool> tem(n);
    int maior = -INF;
    for(int i = 0; i < n; i++) {
        cin >> alturas[i]; 
        tem[alturas[i]] = true;
        maior = max(maior, alturas[i]);
    }
    int ans = 0;
    for(int i = 1; i < maior; i++){
        if(!tem[i]) continue;
        for(int j = 0; j < n; j++){
            if(alturas[j] == i){
                alturas[j]++;
                while(j+1 < n and alturas[j+1] == i) {j++; alturas[j]++;}
                ans++;
            }
            tem[i+1] = true;
        }
    }
    cout << ans << endl;

    return 0;
}