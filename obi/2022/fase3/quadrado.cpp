#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    if(n%2){
        int init = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << init << " ";
                init++;
            }
            cout << endl;
        }
    }
    return 0;
}
