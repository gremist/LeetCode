// LeetCode 18 4Sum.cpp

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i + 3 < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j + 2 < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1, t2sum = target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] < t2sum) {
                        l++;
                    } else if (nums[l] + nums[r] > t2sum) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
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
        }
        return ans;
    }
};