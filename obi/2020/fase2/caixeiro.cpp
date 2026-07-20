#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj (n+1, vector<int>(n+1, 0));
    int num_caminhos = n * (n-1) / 2;
    for(int i = 0; i < num_caminhos; i++){
        int a, b, t;
        cin >> a >> b >> t;
        dp[a][b] = t;
        dp[b][a] = t;
    }
    
    return 0;

}