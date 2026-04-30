#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &n : nums)
        cin >> n;
    unordered_map<int, int> pos;

    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    int maior = 1;
    int i, j;
    i = 0;
    j = 1;

    pos[nums[i]] = 0;

    for (; j < n; j++)
    {
        if (pos.find(nums[j]) != pos.end())
            i = max(i, pos[nums[j]] + 1);

        maior = max(maior, j - i + 1);
        pos[nums[j]] = j;
    }

    cout << maior << "\n";
}