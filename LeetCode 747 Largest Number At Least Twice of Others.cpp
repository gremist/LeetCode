// LeetCode 747 Largest Number At Least Twice of Others.cpp

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != max_idx && nums[i] * 2 > nums[max_idx]) {
                return -1;
            }
        }
        return max_idx;
    }
};