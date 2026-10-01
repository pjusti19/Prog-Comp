#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int,int> ump;
    int prefix(int i, vector<int>& BIT){
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += BIT[i];
        return ret;
    }
    void update(int i, int x, vector<int>&BIT){
        for(; i < BIT.size(); i += i & -i) BIT[i] += x;
    }
    vector<int> countSmaller(vector<int>& nums) {
       vector<int> BIT(100001, 0);
       vector<int> counts (nums.size(), 0);
       vector<int> b = nums;
       sort(b.begin(), b.end());
       b.erase(unique(b.begin(), b.end()), b.end());
       int count = 1;
       for(int i = 0; i < b.size(); i++) ump[b[i]] = count++;
       for(int i = nums.size()-1; i >= 0; i--){
        counts[i] = prefix(ump[nums[i]]-1, BIT);
        update(ump[nums[i]], 1, BIT);
       }
       return counts;
    }
};