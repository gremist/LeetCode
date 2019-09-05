// LeetCode 1051 Height Checker.cpp

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != sorted[i]) {
                ans++;
            }
        }
        return ans;
    }
};