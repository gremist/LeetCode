// LeetCode 78 Subsets.cpp

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, nums, 0);
        return ans;
    }

private:
    void backtrack(vector<vector<int>> &ans, vector<int> &cur, vector<int> &nums, int ni) {
        ans.push_back(cur);
        for (int i = ni; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtrack(ans, cur, nums, i + 1);
            cur.pop_back();
        }
    }
};