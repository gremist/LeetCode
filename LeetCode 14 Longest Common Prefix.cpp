// LeetCode 14 Longest Common Prefix.cpp

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string ans;
        for (int j = 0; j < strs[0].size(); j++) {
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[0][j] != strs[i][j]) {
                    return ans;
                }
            }
            ans.push_back(strs[0][j]);
        }
        return ans;
    }
};