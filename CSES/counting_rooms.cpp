#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];

    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int rooms = 0;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (grid[i][j] == '.')
            {
                rooms++;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '#';
                while (!q.empty())
                {
                    auto cell = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int cx = cell.first + dx[k];
                        int cy = cell.second + dy[k];
                        if (cx < 0 || cx >= h || cy < 0 || cy >= w) continue;
                        if (grid[cx][cy] != '.') continue;
                        grid[cx][cy] = '#';
                        q.push({cx, cy});
                    }
                }
            }

    cout << rooms << "\n";

    return 0;
}