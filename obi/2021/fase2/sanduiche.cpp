#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {

  int ingredientes, num_restricoes, possibilidades_possiveis;

  cin >> ingredientes >> num_restricoes;

  int total_posibilidades = (pow(2, ingredientes) - 1);

  if (num_restricoes > 0) {
    vector<int> combinacoes(num_restricoes);

    for (int i = 0; i < num_restricoes; i++) {
      int ingrediente_um, ingrediente_dois;
      cin >> ingrediente_um >> ingrediente_dois;
      combinacoes[i] = (1 << (ingrediente_um - 1)) | (1 << (ingrediente_dois - 1));
    }

    possibilidades_possiveis = 0;
    
    for (int i = 1; i <= total_posibilidades; i++) {
      int aux = 0;
      for (int j = 0; j < combinacoes.size(); j++) {
        if ((combinacoes[j] & i) == combinacoes[j])
          break;
        aux++;
      }
      if (aux == combinacoes.size())
        possibilidades_possiveis++;
    }

    cout << possibilidades_possiveis << endl;
  } else
    cout << total_posibilidades << endl;

  return 0;
}