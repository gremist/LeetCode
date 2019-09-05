// LeetCode 260 Single Number III.cpp

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int d = 0;
        for (int n : nums) {
            d ^= n;
        }
        d &= -d;
        
        int ans1 = 0, ans2 = 0;
        for (int n : nums) {
            if (n & d) {
                ans1 ^= n;
            } else {
                ans2 ^= n;
            }
        }
        return {ans1, ans2};
    }
};