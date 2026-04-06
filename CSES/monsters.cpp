#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  vector<pair<int, int>> monsters;
  pair<int, int> my_pos;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'A')
        my_pos = {i, j};
      else if (grid[i][j] == 'M')
        monsters.push_back({i, j});
    }
  }

  if (my_pos.first <= 0 || my_pos.first >= n - 1 || my_pos.second <= 0 ||
      my_pos.second >= m - 1) {
    cout << "YES" << "\n" << 0 << "\n";
    return 0;
  }

  vector<vector<char>> parent(n, vector<char>(m, 0));
  queue<pair<int, int>> qm, qa;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  char dir[4] = {'U', 'R', 'D', 'L'};

  for (int i = 0; i < monsters.size(); i++) {
    qm.push(monsters[i]);
    grid[monsters[i].first][monsters[i].second] = '#';
  }
  qa.push(my_pos);
  grid[my_pos.first][my_pos.second] = '#';
  while (!qa.empty()) {
    int sizeM = qm.size();
    int sizeA = qa.size();
    for (int i = 0; i < sizeM; i++) {
      pair<int, int> curr = qm.front();
      qm.pop();
      for (int j = 0; j < 4; j++) {
        int x = curr.first + dx[j];
        int y = curr.second + dy[j];
        if (x < 0 || x >= n || y < 0 || y >= m)
          continue;
        if (grid[x][y] == '#')
          continue;
        qm.push({x, y});
        grid[x][y] = '#';
      }
    }
    for (int i = 0; i < sizeA; i++) {
      pair<int, int> my_curr = qa.front();
      qa.pop();
      for (int j = 0; j < 4; j++) {
        int x = my_curr.first + dx[j];
        int y = my_curr.second + dy[j];
        if (grid[x][y] == '#')
          continue;
        qa.push({x, y});
        grid[x][y] = '#';
        parent[x][y] = dir[j];
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
          string path;
          while (true) {
            path.push_back(parent[x][y]);
            if (parent[x][y] == 'U')
              x++;
            else if (parent[x][y] == 'R')
              y--;
            else if (parent[x][y] == 'D')
              x--;
            else if (parent[x][y] == 'L')
              y++;
            if (x == my_pos.first && y == my_pos.second)
              break;
          }
          reverse(path.begin(), path.end());
          cout << "YES" << "\n" << path.size() << "\n" << path << "\n";
          return 0;
        }
      }
    }
  }

  cout << "NO" << "\n";

  return 0;
}