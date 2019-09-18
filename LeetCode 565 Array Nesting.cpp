// LeetCode 565 Array Nesting.cpp

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> visit(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i]) {
                continue;
            }
            int count = 0;
            for (int j = i; !visit[j]; j = nums[j]) {
                visit[j] = true;
                count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};