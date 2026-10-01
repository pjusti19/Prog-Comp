#include <bits/stdc++.h>

using namespace std;

class NumArray {
    int n;
    vector<int> BIT;
    vector<int> nums;

    int prefix(int i){
        int ret = 0;
        for(; i > 0; i -= i & -i) ret += BIT[i];
        return ret;
    }

public:
    NumArray(vector<int>& a): n(a.size()), BIT(a.size()+1, 0), nums(a)  {
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j += j & -j) BIT[j] += nums[i];
        }
    }
    
    void update(int index, int val) {
        for(int i = index+1; i <= n; i += i & - i) BIT[i] += val-nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        return prefix(right+1) - prefix(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */