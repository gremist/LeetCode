// LeetCode 645 Set Mismatch.cpp

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]);
            ans[1] ^= val ^ (i + 1);
            if (nums[val - 1] > 0) {
                nums[val - 1] = -nums[val - 1];
            } else {
                ans[0] = val;
            }
        }
        ans[1] ^= ans[0];
        return ans;
    }
};