#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int MAX = max(n, 2 * m + 5);
    queue<pair<int, int>> q;
    vector<bool> visited(MAX);
    q.push({n, 0});
    visited[n] = true;
    while (!q.empty())
    {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (curr == m)
        {
            cout << dist << "\n";
            break;
        }

        if (curr * 2 < MAX && !visited[curr * 2])
        {
            visited[curr * 2] = true;
            q.push({curr * 2, dist + 1});
        }

        if (curr - 1 >= 0 && !visited[curr - 1])
        {
            visited[curr - 1] = true;
            q.push({curr - 1, dist + 1});
        }
    }

    return 0;
}