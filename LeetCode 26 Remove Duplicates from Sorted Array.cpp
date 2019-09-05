// LeetCode 26 Remove Duplicates from Sorted Array.cpp

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int n : nums) {
            if (len == 0 || n != nums[len - 1]) {
                nums[len++] = n;
            }
        }
        return len;
    }
};