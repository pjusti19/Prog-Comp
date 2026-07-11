#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> proibidos(m);
    for(auto &p : proibidos){
        int primeiro, segundo;
        cin >> primeiro >> segundo;
        p = (1 << (primeiro-1)) | (1 << (segundo-1));
    }
    int total_possibilidades = pow(2, n)-1;
    if(m != 0){
        int sanduiches_possiveis = total_possibilidades;
        for(int i = 1; i <= total_possibilidades; i++){
            for(auto &p : proibidos){
                if((i & p) == p){
                    sanduiches_possiveis--;
                    break;
                }
            }
        }
        cout << sanduiches_possiveis << "\n";
    }
    else cout << total_possibilidades << "\n";
    return 0;

}