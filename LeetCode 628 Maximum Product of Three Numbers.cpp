// LeetCode 628 Maximum Product of Three Numbers.cpp

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int ns = nums.size();
        sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[ns - 1], nums[ns - 3] * nums[ns - 2] * nums[ns - 1]);
    }
};