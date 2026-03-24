#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cities_num, towers_num;
    cin >> cities_num >> towers_num;
    vector<long long> cities_pos(cities_num);
    vector<long long> towers_pos(towers_num);
    for (long long &city : cities_pos)
        cin >> city;
    for (long long &tower : towers_pos)
        cin >> tower;

    vector<long long> result(cities_num);
    for (int i = 0; i < cities_num; i++)
    {
        long long pos;
        auto it = lower_bound(towers_pos.begin(), towers_pos.end(), cities_pos[i]);
        if (abs(towers_pos[it - towers_pos.begin()] - cities_pos[i]) < abs(cities_pos[i] - towers_pos[it - towers_pos.begin() - 1]))
            result[i] = towers_pos[it - towers_pos.begin()] - cities_pos[i];
        else
            result[i] = cities_pos[i] - towers_pos[it - towers_pos.begin() - 1];
    }
    sort(result.begin(), result.end());
    cout << result[cities_num-1] << "\n";
    return 0;
}