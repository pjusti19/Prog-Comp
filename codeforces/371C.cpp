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
    __int128 needB = (__int128)perB * x;
    __int128 needS = (__int128)perS * x;
    __int128 needC = (__int128)perC * x;

    __int128 buyB = needB - haveB; if (buyB < 0) buyB = 0;
    __int128 buyS = needS - haveS; if (buyS < 0) buyS = 0;
    __int128 buyC = needC - haveC; if (buyC < 0) buyC = 0;

    __int128 cost = buyB * priceB + buyS * priceS + buyC * priceC;
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
