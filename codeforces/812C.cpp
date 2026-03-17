#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long check(long long &k, vector<long long> &costs, long long &limit,
                long long &budget) {
  vector<long long> adjusted_costs(limit);
  for (int i = 0; i < limit; i++)
    adjusted_costs[i] = costs[i] + (i + 1) * k;

  if (k < limit)
    nth_element(adjusted_costs.begin(), adjusted_costs.begin() + k,
                adjusted_costs.end());

  long long sum = 0;
  for (int i = 0; i < k; i++)
    sum += adjusted_costs[i];

  if (sum <= budget)
    return sum;
  else
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long amount, budget;
  cin >> amount >> budget;
  vector<long long> costs(amount);

  for (long long &cost : costs)
    cin >> cost;

  long long low = 0;
  long long high = amount;
  long long mid = 0;
  long long max_sum = 0;
  long long max_k = 0;

  while (low < high) {
    long long result = 0;
    mid = low + (high - low + 1) / 2;
    result = check(mid, costs, amount, budget);
    if (result > 0) {
      low = mid;
      max_k = mid;
      max_sum = result;
    } else
      high = mid - 1;
  }

  cout << max_k << " " << max_sum << "\n";
  return 0;
}