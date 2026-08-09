#include <bits/stdc++.h>
 
using namespace std;
 
#define BINGOS 3
#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
 
int main(){ _
    int n,m; cin >> n >> m;
    vector<int> vagas(n+1);
    vector<int> alunos(n+1,0);
    vector<vector<int>> matriculas(n+1);
    for(int i = 1; i <= n; i++) cin >> vagas[i];
    for(int i = 0; i < m; i++){
        int matricula, mats; cin >> matricula >> mats;
        stack<int> st;
        for(int j = 0; j < mats; j++){
            int in; cin >> in;
            if(vagas[in] > 0) st.push(in);
        }
        if(st.size() == mats){
            while(!st.empty()){
                int topo = st.top();
                st.pop();
                vagas[topo]--;
                alunos[topo]++;
                matriculas[topo].push_back(matricula);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << alunos[i];
        for(auto& mat:matriculas[i]) cout << " " << mat;
        cout << endl;
    }
    return 0;
}