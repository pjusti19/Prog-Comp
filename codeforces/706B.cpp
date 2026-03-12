#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (int i = a; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int shops_number;
    cin >> shops_number;

    vector<long long> prices(shops_number);
    loop(i, 0, shops_number){
        cin >> prices[i];
    }

    int number_days;
    cin >> number_days;

    vector<long long> budgets(number_days);
    loop(i, 0, number_days){
        cin >> budgets[i];
    }

    sort(prices.begin(), prices.end());

    loop(i, 0, number_days){
        auto lb = upper_bound(prices.begin(), prices.end(), budgets[i]);
        cout << (lb - prices.begin()) << "\n";
    }

    return 0;
}