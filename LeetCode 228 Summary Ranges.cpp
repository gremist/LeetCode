// LeetCode 228 Summary Ranges.cpp

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i + 1 >= nums.size() || nums[i] + 1 != nums[i + 1]) {
                if (i > j) {
                    ans.push_back(to_string(nums[j]) + "->" + to_string(nums[i]));
                } else {
                    ans.push_back(to_string(nums[i]));
                }
                j = i + 1;
            }
        }
        return ans;
    }
};