#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> freq(n, 0);
    for (int &num : nums)
    {
        cin >> num;
        freq[num]++;
    }

    int sum = 0;
    int mn = INT_MAX;
    for(int i = 0; i < n; i++){
        if(freq[i] == 0) break;
        mn = min(freq[i], mn);
        sum += min(mn, k);
    }

    cout << sum << "\n";

    return 0;
}