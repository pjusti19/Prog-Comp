#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int count = 0;
    long long sum = 0;
    unordered_map<long long, int> sums;
    sums[0] = 1;
    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];
      if (sums[sum - k] > 0) 
        count += sums[sum - k];
      sums[sum]++;
    }
    return count;
  }
};