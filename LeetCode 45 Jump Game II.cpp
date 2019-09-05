// LeetCode 45 Jump Game II.cpp

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        for (int i = 0, j = 0, k = 0; i < nums.size() - 1; i++) {
            j = max(i + nums[i], j);
            if (i >= k) {
                k = j;
                step++;
            }
        }
        return step;
    }
};