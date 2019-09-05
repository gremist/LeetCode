// LeetCode 137 Single Number II.cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int n : nums) {
            once  = (once  ^ n) & ~twice;
            twice = (twice ^ n) & ~once;
        }
        return once;
    }
};