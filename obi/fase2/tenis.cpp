#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> pontuacoes(4);

  for (int i = 0; i < 4; i++)
    cin >> pontuacoes[i];

  sort(pontuacoes.begin(), pontuacoes.end());
  cout << abs(pontuacoes[0] + pontuacoes[3] - pontuacoes[1] - pontuacoes[2]) << endl;

  return 0;
}