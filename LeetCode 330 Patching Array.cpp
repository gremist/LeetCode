// LeetCode 330 Patching Array.cpp

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i = 0, cnt = 0;
        long miss = 1;
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                miss *= 2;
                cnt++;
            }
        }
        return cnt;
    }
};