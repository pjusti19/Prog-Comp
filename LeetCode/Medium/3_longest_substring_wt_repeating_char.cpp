#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<bool> hasfound(256, false);
    int length = s.length();
    int left = 0;
    int right = 0;
    int max_length = 0;

    if (length == 0 || length == 1)
      return length;

    while (right < length) {
      while (hasfound[s[right]] == true) {
        hasfound[s[left]] = false;
        left++;
      }
      hasfound[s[right]] = true;
      max_length = max(max_length, right - left + 1);
      right++;
    }

    return max_length;
  }
};