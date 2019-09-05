// LeetCode 80 Remove Duplicates from Sorted Array II.cpp

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (int n : nums) {
            if (len < 2 || n != nums[len - 2]) {
                nums[len++] = n;
            }
        }
        return len;
    }
};