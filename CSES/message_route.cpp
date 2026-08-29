#include <bits/stdc++.h>
using namespace std;

void bfs(queue<int> &q, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent, int &dest, bool &found)
{
    q.push(1);
    visited[1] = true;
    parent[1] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == dest)
        {
            found = true;
            break;
        }

        for (int el : adj[curr])
        {
            if (!visited[el])
            {
                parent[el] = curr;
                visited[el] = true;
                q.push(el);
            }
        }
    }
}

for(int i = 0; i < n; i++){
    for(auto& j: matriz_adj[i]){
        cout << j << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<int> q;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n+1);
    vector<int> parent(n+1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;
    bfs(q, adj, visited, parent, n, found);

    if (found)
    {
        int dist = 1;
        int dest = parent[n];
        vector<int> path;
        path.push_back(n);

        while (true)
        {
            path.push_back(dest);
            dist++;
            dest = parent[dest];
            if (dest == 0)
                break;
        }
        reverse(path.begin(), path.end());

        cout << dist << "\n";
        for (int i = 0; i < path.size() - 1; i++)
            cout << path[i] << " ";
        cout << n << "\n";
    }
    else
        cout << "IMPOSSIBLE" << "\n";

    return 0;
}