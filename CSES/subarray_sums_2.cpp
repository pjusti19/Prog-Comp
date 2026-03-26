#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int array_size;
    long long  target_sum;
    cin >> array_size >> target_sum;

    vector<long long> numbers(array_size);
    for(long long &number: numbers) cin >> number;

    map<long long, int> sums;

    long long count = 0;
    long long current_sum = 0;
    sums[0] = 1;
    for(int i = 0; i < array_size; i++){
        current_sum += numbers[i];
        if(sums.find(current_sum - target_sum) != sums.end())
            count += sums[current_sum - target_sum];
        sums[current_sum]++;
    }

    cout << count << "\n";

    return 0;
}
