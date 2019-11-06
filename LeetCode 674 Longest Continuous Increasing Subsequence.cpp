// LeetCode 674 Longest Continuous Increasing Subsequence.cpp

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        for (int i = 0, last = -1; i < nums.size(); i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) {
                last = i - 1;
            }
            ans = max(ans, i - last);
        }
        return ans;
    }
};