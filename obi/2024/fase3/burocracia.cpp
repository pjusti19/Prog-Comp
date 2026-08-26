// #include <iostream>
// #include <queue>
// #include <numeric>
// #include <unordered_map>

// using namespace std;

// #define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n'

// typedef long long ll;

// const int INF = 0x3f3f3f3f;

// int main() { _ 
//     int n; cin >> n;
//     vector<int> sup(n+1, -1);
//     vector<vector<int>> rev(n+1);
//     for(int i = 2; i < n+1; i++) {cin >> sup[i]; rev[sup[i]].push_back(i);}
//     int q; cin >> q;
//     for(int i = 0; i < q; i++){
//         int t, v; cin >> t;
//         if(t == 1){
//             int k; cin >> v >> k;
//             for(int j = 0; j < k; j++) v = sup[v];
//             cout << v << endl;
//         }
//         else{
//             cin >> v;
//             queue<int> q;
//             vector<int> rem;
//             q.push(v);
//             while(!q.empty()){
//                 int curr = q.front(); q.pop();
//                 if(curr != v and sup[curr] != v) sup[curr] = v; 
//                 if(sup[curr] == v) rem.push_back(curr);
//                 for(int&r:rev[curr]) q.push(r);
//             }
//         }
//     }

//     return 0;
// }
// vou voltar nesse dps q estudar fenwick e segtree