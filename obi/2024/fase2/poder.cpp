#include <bits/stdc++.h>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> poderes(n, vector<int>(m, 0));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> poderes[i][j];


  return 0;
}