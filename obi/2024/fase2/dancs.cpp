#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, p;
  cin >> n >> m >> p;

  vector<int> idx_linhas(n), idx_colunas(m);
  
  for(int i = 0; i < n; i++) idx_linhas[i] = i;
  for(int i = 0; i < m; i++) idx_colunas[i] = i;

  for (int i = 0; i < p; i++) {
    char mov;
    int grp1, grp2;
    cin >> mov >> grp1 >> grp2;
    if (mov == 'C') swap(idx_colunas[grp1-1], idx_colunas[grp2-1]);
    else swap(idx_linhas[grp1-1], idx_linhas[grp2-1]);
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(j == m-1) cout << (idx_linhas[i]*m) + idx_colunas[j] + 1 << "\n";
        else cout << (idx_linhas[i]*m) + idx_colunas[j] + 1 << " ";
    }
  }

  return 0;
}