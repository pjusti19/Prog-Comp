#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{

    string cartas;
    vector<int> baralho(52, 0);
    cin >> cartas;

    vector<int> count = {13, 13, 13, 13};
    vector<bool> error = {false, false, false, false};

    for (int i = 0; i < (int)cartas.size(); i += 3)
    {
        char nipe;
        int numero = ((cartas[i] - '0') * 10) + (cartas[i + 1] - '0');
        numero--;
        int index;

        if (cartas[i + 2] == 'C')
            nipe = 0;
        else if (cartas[i + 2] == 'E')
            nipe = 1;
        else if (cartas[i + 2] == 'U')
            nipe = 2;
        else if (cartas[i + 2] == 'P')
            nipe = 3;

        index = nipe * 13 + numero;

        baralho[index]++;
        if (baralho[index] == 2)
            error[nipe] = true;
        else
            count[nipe]--;
    }

    for (int i = 0; i < 4; i++)
            error[i] ? cout << "erro\n" : cout << count[i] << "\n";

    return 0;
}
