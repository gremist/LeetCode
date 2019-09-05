// LeetCode 455 Assign Cookies.cpp

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ans = 0;
        for (int cookie : s) {
            if (ans >= g.size()) {
                break;
            }
            if (cookie >= g[ans]) {
                ans++;
            }
        }
        return ans;
    }
};