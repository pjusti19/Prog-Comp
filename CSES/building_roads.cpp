#include <iostream>
#include <vector>
#include <queue>    

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, r;
  cin >> c >> r;
  vector<vector<int>> adj(c + 1);

  for (int i = 0; i < r; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<bool> visited(c + 1);
  vector<int> components;
  queue<int> q;

  for (int i = 1; i <= c; i++) {
    if (visited[i] == true)
      continue;
    q.push(i);
    visited[i] = true;
    components.push_back(i);
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      for (int &el : adj[curr]) {
        if (visited[el] == true)
          continue;
        visited[el] = true;
        q.push(el);
      }
    }
  }
  int roads = components.size() - 1;
  cout << roads << "\n";

  for(int i = 0; i < roads; i++)
    cout << components[i] << " " << components[i+1] << "\n";

  return 0;
}