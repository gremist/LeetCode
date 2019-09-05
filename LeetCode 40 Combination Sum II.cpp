// LeetCode 40 Combination Sum II.cpp

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
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
            if (i == ci || candidates[i] != candidates[i - 1]) {
                cur.push_back(candidates[i]);
                backtrack(ans, cur, candidates, i + 1, target - candidates[i]);
                cur.pop_back();
            }
        }
    }
};