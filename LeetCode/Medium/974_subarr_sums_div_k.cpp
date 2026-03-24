#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    unordered_map<int, int> mods;
    int count = 0;
    int sum = 0;
    mods[0] = 1;
    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];
      int mod = sum % k;
      if (mod < 0)
        mod = k + mod;
      if (mods[mod] > 0)
        count += mods[mod];
      mods[mod]++;
    }
    return count;
  }
};