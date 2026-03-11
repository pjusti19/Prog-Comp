#include <iostream>
#include <vector>

using namespace std;

int main() {

  int tamanho_lista = 0;
  cin >> tamanho_lista;

  vector<int> lista(tamanho_lista);

  for (int i = 0; i < tamanho_lista; i++)
    cin >> lista[i];

  int inicio, fim, num_contracoes;
  inicio = num_contracoes = 0;
  fim = lista.size() - 1;

  while ((inicio != fim) && (inicio < fim)) {
    if (lista[inicio] == lista[fim]) {
      inicio++;
      fim--;
    } else if (lista[inicio] < lista[fim]) {
      num_contracoes++;
      lista[inicio + 1] += lista[inicio];
      inicio++;
    } else {
      num_contracoes++;
      lista[fim - 1] += lista[fim];
      fim--;
    }
  }

  cout << num_contracoes << endl;

  return 0;
}