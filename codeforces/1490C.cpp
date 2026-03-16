#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    long long number;
    bool found = false;
    cin >> number;

    long long low = 1;
    long long high = floor(cbrt(number));

    while (low <= high) {
      long long result = (low * low * low) + (high * high * high);
      if (result == number) {
        found = true;
        break;
      } else if (result > number)
        high--;
      else if (result < number)
        low++;
    }
    if (found)
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  return 0;
}