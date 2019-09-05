// LeetCode 41 First Missing Positive.cpp

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int &n : nums) {
            while (0 < n && n <= nums.size() && n != nums[n - 1]) {
                swap(n, nums[n - 1]);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};