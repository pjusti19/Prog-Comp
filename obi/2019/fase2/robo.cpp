#include <bits/stdc++.h>

using namespace std;

#define _ ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n';

typedef long long ll;

const int INF = 0x3f3f3f3f;

int main(){

    int i_x, i_y, f_x, f_y; cin >> i_x >> i_y >> f_x >> f_y;
    int n; cin >> n;
    set<int> x_s, y_s;
    x_s.insert(i_x); x_s.insert(f_x);  
    y_s.insert(i_y); y_s.insert(f_y);
    vector<tuple<int,int,int,int>> regioes;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;  
        x_s.insert(x1);
        x_s.insert(x2);
        y_s.insert(y1);
        y_s.insert(y2);
        regioes.push_back({x1, y1, x2, y2});
    }
    int cont = 0;
    unordered_map<int, int> to_c_x, to_c_y, to_dc_x, to_dc_y;
    for(auto& x: x_s){
        to_c_x[x] = cont; 
        to_dc_x[cont] = x;
        cont++;
    }
    cont = 0;
    for(auto& y: y_s){
        to_c_y[y] = cont;
        to_dc_y[cont] = y; 
        cont++;
    }
    int largura = to_c_x.size();
    int comprimento = to_c_y.size();
    int init_c_x = to_c_x[i_x];
    int init_c_y =  to_c_y[i_y];
    int dest_c_x = to_c_x[f_x];
    int dest_c_y = to_c_y[f_y];
    vector<vector<int>> grid(largura, vector<int>(comprimento, 1));
    priority_queue<tuple<int,int,int>> pq;
    vector<vector<int>> dist(largura, vector<int>(comprimento, INF));
    int dx[4] = {0, 1, 0, -1}; int dy[4] = {-1, 0, 1, 0};
    int ans = -1;
    for(auto& [x1, y1, x2, y2] : regioes){
        int x1_c = to_c_x[x1], x2_c = to_c_x[x2];
        int y1_c = to_c_y[y1], y2_c = to_c_y[y2];
        for(int x = x1_c; x <= x2_c; x++){
            for(int y = y1_c; y <= y2_c; y++)
                grid[x][y] = 0;
        }
    }
    pq.push({-0, init_c_x, init_c_y});
    while(!pq.empty()){
        auto [p, x, y] = pq.top();
        p = -p;
        pq.pop();
        if(dist[x][y] <= p) continue;
        dist[x][y] = p;
        if(x == dest_c_x and y == dest_c_y) {ans = p; break;}
        for(int i = 0; i < 4; i++){
            int n_x = x + dx[i]; int n_y = y + dy[i];
            if(n_x < 0 or n_x >= largura or n_y < 0 or n_y >= comprimento) continue;
            int dist_real = abs(to_dc_x[x] - to_dc_x[n_x]) + abs(to_dc_y[y] - to_dc_y[n_y]);
            int peso_real = dist_real * grid[n_x][n_y];
            if(dist[n_x][n_y] > p + peso_real)  pq.push({-(p + peso_real), n_x, n_y});
        }
    }
    cout << ans << endl;
}

// nao tankei - depois volto aqui