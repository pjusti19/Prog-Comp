#include <iostream>
#include <vector>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){ _ 
    int n; cin >> n;
    vector<int> deg(n+1, 0);
    vector<pair<int,int>> intervalos;
    int ultimo = 0;
    bool eh_seq = false;
    for(int i = 1; i < n+1; i++){
        cin >> deg[i];
        if(deg[i] != -1){
            if(eh_seq){
                intervalos.push_back({ultimo, i});
                eh_seq = false;
            }
            ultimo = i;
        }
        else eh_seq = true;
    }
    if(eh_seq) intervalos.push_back({ultimo, n+1});
    eh_seq = false;
    int num_seq = -1;
    //for(auto [a, b] :intervalos) cout << a << " " << b << endl;
    for(int i = 1; i < n+1; i++){
        if(deg[i] == -1){
            if(!eh_seq){
                num_seq++;
                eh_seq = true;
                auto [e, d] = intervalos[num_seq];
                if(d == n + 1) deg[i] = deg[i-1]+1;
                else if(deg[e] == 0) deg[i] = deg[d]+(d-i);
                else if(deg[d]+(d-i) >= deg[i-1]+1) deg[i] = deg[i-1]+1;
                else if(deg[d]+(d-i) == deg[i-1]) deg[i] = deg[i-1];
                else if(deg[d]+(d-i) < deg[i-1]) deg[i] = deg[i-1]-1;
            }
            else{
                auto [e, d] = intervalos[num_seq];
                if(d == n + 1) deg[i] = deg[i-1]+1;
                else if(deg[e] == 0) deg[i] = deg[d]+(d-i);
                else if(deg[d]+(d-i) >= deg[i-1]+1) deg[i] = deg[i-1]+1;
                else if(deg[d]+(d-i) == deg[i-1]) deg[i] = deg[i-1];
                else if(deg[d]+(d-i) < deg[i-1]) deg[i] = deg[i-1]-1;
            }
        }
        else eh_seq = false;
    }
    for(int i = 1; i < n+1; i++){
        if(i == n) cout << deg[i] << endl;
        else cout << deg[i] << " ";
    }
    return 0;
}