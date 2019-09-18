// LeetCode 213 House Robber II.cpp

class Solution {
public:
    int rob(vector<int>& nums) {
        int ns = nums.size();
        if (ns == 0) return 0;
        if (ns == 1) return nums[0];
        
        vector<int> dp1(2), dp2(2);
        for (int i = 0; i < ns - 1; i++) {
            dp1[i % 2] = max(dp1[i % 2] + nums[i], dp1[(i + 1) % 2]);
            dp2[i % 2] = max(dp2[i % 2] + nums[i + 1], dp2[(i + 1) % 2]);
        }
        return max(dp1[ns % 2], dp2[ns % 2]);
    }
};