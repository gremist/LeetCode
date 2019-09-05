// LeetCode 238 Product of Array Except Self.cpp

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < ans.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        for (int i = ans.size() - 2, p = 1; i >= 0; i--) {
            p *= nums[i + 1];
            ans[i] *= p;
        }
        return ans;
    }
};