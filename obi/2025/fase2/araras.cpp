#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int needed_cages = (n - 1) * 4 + n;
    if (needed_cages <= m)
        cout << "S" << "\n";
    else
        cout << "N" << "\n";

    return 0;
}