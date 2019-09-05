// LeetCode 152 Maximum Product Subarray.cpp

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums.front(), dpmax = ans, dpmin = ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                swap(dpmax, dpmin);
            }
            dpmax = max(dpmax * nums[i], nums[i]);
            dpmin = min(dpmin * nums[i], nums[i]);
            ans = max(ans, dpmax);
        }
        return ans;
    }
};