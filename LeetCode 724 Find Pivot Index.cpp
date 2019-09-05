// LeetCode 724 Find Pivot Index.cpp

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left_sum = 0, sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum * 2 + nums[i] == sum) {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};