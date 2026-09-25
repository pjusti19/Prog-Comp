#include <iostream>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3fll;

int n, k; 
vector<vector<int>> adj;

bool ok(int raio){
    stack<int> st;
    int min = 0;
    vector<int> visited(n+1, false);
    vector<int> dist(n+1, 0);
    st.push(1);
    visited[1] = true;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(dist[u] == raio){
            min++;
            dist[u] = -1;
        }
        if(min > k) return false;
        for(int&a:adj[u]){
            if(!visited[a]){
                st.push(a);
                visited[a] = true;
                dist[a] += dist[u] + 1;
            }
        }
    }
    return true;
}


int main(){ _ 
    cin >> n >> k;
    adj = vector<vector<int>> (n+1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int l, r; l = 0; r = 300001;
    while(l < r){
        int m = l + (r - l) / 2;
        if(ok(m)) r = m;
        else l = m+1;
    }
    cout << r << endl;
    return 0;
}
