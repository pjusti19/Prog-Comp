#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int days;
    cin >> days;

    vector<int> money(days);
    for (int &x : money)
        cin >> x;

    int i = 0;
    int max_streak = 1;
    int streak = 1;
    for (int j = 1; j < days; i++, j++)
    {
        if (!(money[i] <= money[j]))
        {
            i = j - 1;
            streak = 1;
        }
        else streak++;
        max_streak = max(max_streak, streak);
    }

    cout << max_streak << "\n";

    return 0;
}