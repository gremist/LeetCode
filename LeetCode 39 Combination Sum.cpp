// LeetCode 39 Combination Sum.cpp

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, cur, candidates, 0, target);
        return ans;
    }
    
private:
    void backtrack(vector<vector<int>> &ans, vector<int> &cur, vector<int>& candidates, int ci, int target) {
        if (target  < 0) return;
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        for (int i = ci; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(ans, cur, candidates, i, target - candidates[i]);
            cur.pop_back();
        }
    }
};