// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// #define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
// #define endl '\n';

// typedef long long ll;

// const int INF = 0x3f3f3f3f;

// int s, t;
// int main(){
//     cin >> s >> t;
//     vector<vector<pair<int,int>>> adj(s+1);
//     for(int i = 0; i < t; i++){
//         int a, b, c; cin >> a >> b >> c;
//         adj[a].push_back({b, c});
//         adj[b].push_back({a, c});
//     }
//     int q; cin >> q;
//     vector<int> ans(q, -1);
//     for(int i = 0; i < q; i++){
//         int x, m; cin >> x >> m;
//         priority_queue<pair<int,int>> pq;
//         vector<int> dist(s+1, INF);
//         vector<bool> block(s+1, false);
//         queue<pair<int,int>> qu;
//         pq.push({-0, x});
//         bool first = true;
//         while(!pq.empty()){
//             auto [d, u] = pq.top();
//             d = -d;
//             pq.pop();
//             if(dist[u] <= d or block[u]) continue;
//             dist[u] = d;
//             if(u == x and first == false) {ans[i] = d; break;}
//             block[u] = true;
//             qu.push({d, u});
//             while(!qu.empty() and d - m >= qu.front().first){
//                 block[qu.front().second] = false;
//                 qu.pop();
//             }
//             first= false; 
//             for(auto [n_u, n_d] : adj[u])
//                 if(dist[n_u] > n_d + d and !block[n_u]) pq.push({-(n_d + d ), n_u});
//         }
//     }
//     for(auto& a:ans) cout << a << endl;
// }