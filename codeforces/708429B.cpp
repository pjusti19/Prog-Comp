#include <bits/stdc++.h>
 
using namespace std;
 
#define BINGOS 3
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){ _
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(auto& g:grid) cin >> g;
 
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    stack<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()){
        auto [l,c] = q.top();
        q.pop();
        int count = 0;
        for(int i = 0; i < 4; i++){
            int n_l = l + dy[i], n_c = c + dx[i];
            if (n_l < 0 || n_l >= n || n_c < 0 || n_c >= m || grid[n_l][n_c] == '.') continue;
            if((i == 2 or i == 3) and visited[n_l][n_c] == false){
                cout << "Impossivel" << endl;
                return 0;
            }
            if(visited[n_l][n_c] == false) {
                q.push({n_l, n_c});
                count++;
            }
            if(count >= 2){
               cout << "Impossivel" << endl;
               return 0;
            }
            visited[n_l][n_c] = true;
            
        }
    }
 
    cout << "Possivel" << endl;
    return 0;
}