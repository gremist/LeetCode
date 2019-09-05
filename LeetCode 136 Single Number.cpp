// LeetCode 136 Single Number.cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            ans ^= n;
        }
        return ans;
    }
};