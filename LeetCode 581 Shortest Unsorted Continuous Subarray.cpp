// LeetCode 581 Shortest Unsorted Continuous Subarray.cpp

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int l = 0, r = nums.size() - 1;
        while (l <= r && nums[l] == sorted[l]) {
            l++;
        }
        while (l <= r && nums[r] == sorted[r]) {
            r--;
        }
        return r - l + 1;
    }
};