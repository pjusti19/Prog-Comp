#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

int main(){ _
    int l,c; cin >> l >> c;
    vector<string> grid(l);
    for(int i = 0; i < l; i++) cin >> grid[i];
    pair<int,int> h;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j] == 'o') {h = {i,j}; break;}
        }
    }
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    stack<pair<int,int>> st;
    vector<vector<bool>> visited(l, vector<bool>(c, false));
    st.push(h);
    visited[h.first][h.second] = true;
    pair<int,int> ans;
    while(!st.empty()){
        auto [x, y] = st.top();
        st.pop();
        ans = {x,y};
        for(int i = 0; i < 4; i++){
            int n_x = x + dy[i], n_y = y + dx[i];
            if(n_x < 0 or n_x >= l  or n_y < 0 or n_y >= c or grid[n_x][n_y] == '.' or visited[n_x][n_y]) continue;
            visited[n_x][n_y] = true;
            st.push({n_x, n_y});
        }
    }
    cout << ans.first+1 << " " << ans.second+1 << endl;
    return 0;
}