// LeetCode 56 Merge Intervals.cpp

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (vector<int> &itv : intervals) {
            if (!ans.empty() && itv[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], itv[1]);
            } else {
                ans.push_back(itv);
            }
        }
        return ans;
    }
};