#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> poderes(n * m);
  for(int &poder : poderes) cin >> poder;

  sort(poderes.begin(), poderes.end());
  for(int i = 1; i < n*m; i++){
    poderes[i]+= poderes[i-1]
  }
  


  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
    }

  return 0;
}