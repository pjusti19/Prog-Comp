#include <iostream>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    vector<int> nums(6);
    int maior = -INF;
    int idx = -1;
    for(int i = 0; i < 6; i++){
        cin >> nums[i];
        if(maior < nums[i]) {maior = nums[i]; idx = i;}
    }
    for(int i = 0; i < 6; i++){
        if(i == idx) continue;
        for(int j = 0; j < 6; j++){
            if(j == i or j == idx) continue;
            if(nums[i] + nums[j] == maior){
                int soma = 0;
                for(int k = 0; k < 6; k++){
                    if(k == j or k == i or k == idx) continue;
                    soma += nums[k];
                }
                if(soma == maior){cout << "S" << endl; return 0;}
            }
        }
    }
    cout << "N" << endl;

    return 0;
}
