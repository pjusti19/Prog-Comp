#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_estudantes, num_p_juntos, num_p_separados;
    cin >> num_estudantes >> num_p_juntos >> num_p_separados;
    vector<pair<int, int>> juntos(num_p_juntos);
    vector<pair<int, int>> separados(num_p_separados);
    for (auto &i : juntos)
    {
        int a, b;
        cin >> a >> b;
        i = {a, b};
    }
    for (auto &i : separados)
    {
        int a, b;
        cin >> a >> b;
        i = {a, b};
    }

    int quebras = num_p_juntos;
    vector<int> alunos(num_estudantes);
    for (int i = 0; i < num_estudantes; i++){
        int idx;
        cin >> idx;
        alunos[idx-1] = i / 3;
    }
        
    for(auto &i : juntos)
        if(alunos[i.first-1] == alunos[i.second-1]) quebras--;

    for(auto &i : separados)
        if(alunos[i.first-1] == alunos[i.second-1]) quebras++;
    
    cout << quebras << "\n";

    return 0;
}