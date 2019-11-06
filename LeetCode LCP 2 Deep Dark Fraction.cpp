// LeetCode LCP 2 Deep Dark Fraction.cpp

class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        vector<int> ans = {1, 0};
        for (int i = cont.size() - 1; i >= 0; i--) {
            ans[1] += cont[i] * ans[0];
            swap(ans[0], ans[1]);
        }
        return ans;
    }
};