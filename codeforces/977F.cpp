#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

int main(){
    int n;
    unordered_map<ll, int> memo;
    cin >> n;
    vector<ll> nums(n); 
    memo.reserve(n * 2);
    memo.max_load_factor(0.7);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 0; i < n; i++){
        if(memo.count(nums[i] - 1) > 0) memo[nums[i]] = memo[nums[i] - 1] + 1;
        else memo[nums[i]] = 1;
    }
    int tamanho = -1;
    int indice_do_ultimo = -1;
    for(int i = 0; i < n; i++) {
        if(memo[nums[i]] > tamanho){
            tamanho = memo[nums[i]];
            indice_do_ultimo = i;
        }
    }
    cout << tamanho << endl;
    int cauda = nums[indice_do_ultimo] - tamanho + 1;
    for(int i = 0; i < n; i++){
        if(nums[i] == cauda){
            cout << i + 1;
            if(nums[i] != nums[indice_do_ultimo]) cout << " ";
            cauda++;
        }
    }
    cout << endl;
    return 0;
}