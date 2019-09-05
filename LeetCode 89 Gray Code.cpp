// LeetCode 89 Gray Code.cpp

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1 << n);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = i ^ (i / 2);
        }
        return ans;
    }
};