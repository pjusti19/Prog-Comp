#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    int init = 1;
    if(n%2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << init << " ";
                init++;
            }
            cout << endl;
        }
    }else if(n == 2) cout << -1 << endl;
    else{
        for(int i = 0; i < n; i++){
            int fator, count; 
            fator = 1;
            count = 0;
            for(int j = 0; j < n; j++){
                if(init == 1) cout << init << " ";
                else cout << init << " ";
                if(j < n-1)init += fator;
                else init += 1;
                count++;
                if(count == 2){
                    count = 0;
                    if(fator == 1) fator = 3;
                    else fator += 3;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
