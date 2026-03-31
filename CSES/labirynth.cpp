#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int l, c;
  pair<int, int> e, s;
  cin >> l >> c;
  vector<string> grid(l);
  for (int i = 0; i < l; i++) {
    cin >> grid[i];
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == 'A')
        e = {i, j};
      else if (grid[i][j] == 'B')
        s = {i, j};
    }
  }

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  char dir[4] = {'D', 'R', 'U', 'L'};
  vector<vector<char>> parent(l, vector<char>(c, 0));
  queue<pair<int, int>> q;
  bool found = false;

  q.push(e);
  grid[e.first][e.second] = '#';
  while (!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    if (curr.first == s.first && curr.second == s.second) {
      found = true;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int cx = curr.first + dx[i];
      int cy = curr.second + dy[i];
      if (cx < 0 || cx >= l || cy < 0 || cy >= c)
        continue;
      if (grid[cx][cy] == '#')
        continue;
      parent[cx][cy] = dir[i];
      q.push({cx, cy});
      grid[cx][cy] = '#';
    }
  }

  if (!found)
    cout << "NO" << "\n";
  else {
    int x = s.first;
    int y = s.second;
    string path;
    while (!(x == e.first && y == e.second)) {
      char d = parent[x][y];
      path.push_back(d);
      if(d == 'D') x--; else if(d == 'R') y--; else if(d == 'U') x++; else y++;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << "\n" << path.size() << "\n" << path << "\n";
  }

  return 0;
}