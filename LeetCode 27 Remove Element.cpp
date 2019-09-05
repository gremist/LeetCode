// LeetCode 27 Remove Element.cpp

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int n : nums) {
            if (n != val) {
                nums[len++] = n;
            }
        }
        return len;
    }
};