// LeetCode 75 Sort Colors.cpp

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, r = nums.size() - 1;
        while (i <= r) {
            switch (nums[i]) {
            case 0:
                swap(nums[i], nums[l++]);
            case 1:
                i++;
                break;
            case 2:
                swap(nums[i], nums[r--]);
            }
        }
    }
};