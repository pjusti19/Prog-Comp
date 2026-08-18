//#include <bits/stdc++.h>
#include <iostream> 
#include <algorithm>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n, m; cin >> n >> m;
    vector<vector<int>> grid (n, vector<int>(m));
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) cin >> grid[i][j];

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0 , -1};
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        priority_queue<tuple<ll,int,int>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m));
        bool eh_primeiro = true; 
        ll poder = grid[i][j];
        visited[i][j] = true;
        pq.push({-grid[i][j], i, j});
        while(!pq.empty()){
          auto [v, l, c] = pq.top();
          v = -v;
          pq.pop();
          if(!eh_primeiro){
            if(poder >= v) poder+=v;
            else break;
          } 
          for(int k = 0; k < 4; k++){
            int n_l = l + dy[k], n_c = c + dx[k];
            if(n_l < 0 or n_l >= n or n_c < 0 or n_c >= m or visited[n_l][n_c]) continue;
            visited[n_l][n_c] = true;
            pq.push({-grid[n_l][n_c], n_l, n_c});
          }
          if(eh_primeiro) eh_primeiro = false;
        }
        if(j== m-1) cout << poder << endl;
        else cout << poder << " ";
      }
    }
    return 0;
}