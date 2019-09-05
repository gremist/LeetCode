// LeetCode 15 3Sum.cpp

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 2 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1, t2sum = -nums[i];
            while (l < r) {
                if (nums[l] + nums[r] < t2sum) {
                    l++;
                } else if (nums[l] + nums[r] > t2sum) {
                    r--;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};