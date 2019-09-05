// LeetCode 485 Max Consecutive Ones.cpp

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max_len = 0;
        for (int n : nums) {
            count = count * n + n;
            max_len = max(count, max_len);
        }
        return max_len;
    }
};