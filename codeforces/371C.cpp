#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string recipe;
  long long haveB, haveS, haveC;
  long long priceB, priceS, priceC;
  long long budget;

  if (!(cin >> recipe)) return 0;
  cin >> haveB >> haveS >> haveC;
  cin >> priceB >> priceS >> priceC;
  cin >> budget;

  long long perB = count(recipe.begin(), recipe.end(), 'B');
  long long perS = count(recipe.begin(), recipe.end(), 'S');
  long long perC = count(recipe.begin(), recipe.end(), 'C');

  auto canMake = [&](long long x) -> bool {
    long long needB = (long long)perB * x;
    long long needS = (long long)perS * x;
    long long needC = (long long)perC * x;

    long long buyB = needB - haveB; if (buyB < 0) buyB = 0;
    long long buyS = needS - haveS; if (buyS < 0) buyS = 0;
    long long buyC = needC - haveC; if (buyC < 0) buyC = 0;

    long long cost = buyB * priceB + buyS * priceS + buyC * priceC;
    return cost <= budget;
  };

  long long low = 0, high = 1;
  while (canMake(high)) {
    if (high > (long long)4e13) break; 
    high <<= 1;
  }

  while (low < high) {
    long long mid = low + (high - low + 1) / 2;
    if (canMake(mid)) low = mid;
    else high = mid - 1;
  }

  cout << low << '\n';
  return 0;
}
