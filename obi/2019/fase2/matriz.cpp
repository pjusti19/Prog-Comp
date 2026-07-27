#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

int main()
{
    int l, c;
    cin >> l >> c;
    vector<vector<int>> matriz(l, vector<int>(c));
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            cin >> matriz[i][j];
    vector<vector<int>> validade(l-1, vector<int>(c-1));
    for (int i = 0; i < l-1; i++)
        for (int j = 0; j < c-1; j++)
            validade[i][j] = (matriz[i][j] + matriz[i+1][j+1] <= matriz[i][j+1] + matriz[i+1][j]) ? 1 : 0;
    int maior = INT_MIN;
    vector<int> hist(c-1, 0);
    for (int i = 0; i < l-1; i++){
        stack<int> limites_esq, limites_dir;
        vector<int> esq(c-1), dir(c-1);
        for (int j = 0; j < c-1; j++) hist[j] = !validade[i][j]? 0 : hist[j]+1;
        for(int i = 0; i < c-1; i++){
            while(!limites_esq.empty() && hist[limites_esq.top()] >= hist[i]) limites_esq.pop();
            if(limites_esq.empty())esq[i] = -1;
            else esq[i] = limites_esq.top();
            limites_esq.push(i);
        }
        for(int i = c-2; i >=0; i--){
            while(!limites_dir.empty() && hist[limites_dir.top()] >= hist[i]) limites_dir.pop();
            if(limites_dir.empty()) dir[i] = c-1;
            else dir[i] = limites_dir.top();
            limites_dir.push(i);
        }
        for(int i = 0; i < c-1; i++) maior = max(maior, (dir[i] - esq[i]) * (hist[i]+1));
    }
    cout << maior << endl;
    return 0;
}