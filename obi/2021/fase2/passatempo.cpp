// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;
// int main() {

//   int num_linhas, num_colunas;

//   cin >> num_linhas >> num_colunas;

//   map<string, int> resolvidos;
//   vector<vector<string>> linhas(num_linhas, vector<string>(num_colunas));
//   vector<int> soma_linhas(num_linhas);
//   vector<int> soma_colunas(num_colunas);

//   for (int i = 0; i < num_linhas; i++) {
//     for (int j = 0; j < num_colunas; j++)
//       cin >> linhas[i][j];
//     cin >> soma_linhas[i];
//   }

//   for (int i = 0; i < num_colunas; i++)
//     cin >> soma_colunas[i];

//   bool achou = false;
//   int total_variaveis, variaveis_encontradas;
//   total_variaveis = variaveis_encontradas = 0;

//   for (int i = 0; i < num_linhas; i++) {
//     string anterior = "";
//     int count_iguais = 0;
//     for (int j = 0; j < num_colunas; j++) {
//       if (j == 0) {
//         anterior = linhas[i][j];
//         continue;
//       } else if (linhas[i][j] == anterior)
//         count_iguais++;
//     }
//     if (count_iguais == num_colunas-1) {
//       resolvidos[linhas[i][0]] = soma_linhas[i] / num_colunas;
//       achou = true;
//       break;
//     }
//   }

//   if (achou == false) {
//     for (int i = 0; i < num_colunas; i++) {
//       string anterior = "";
//       int count_iguais = 0;
//       for (int j = 0; j < num_linhas; j++) {
//         if (j == 0) {
//           anterior = linhas[j][i];
//           continue;
//         } else if (linhas[j][i] == anterior)
//           count_iguais++;
//       }
//       if (count_iguais == num_colunas-1) {
//         resolvidos[linhas[0][i]] = soma_colunas[i] / num_linhas;
//         achou = true;
//         break;
//       }
//     }
//   }


// }

// vou refatorar, mas nao apaguei pra nao perder a ideia ingenua
