// LeetCode 1160 Find Words That Can Be Formed by Characters.cpp

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> htc(26);
        for (char ch : chars) {
            htc[ch - 'a']++;
        }
        
        int ans = 0;
        for (string &w : words) {
            vector<int> htw(26);
            int i;
            for (i = 0; i < w.size(); i++) {
                if (++htw[w[i] - 'a'] > htc[w[i] - 'a']) {
                    break;
                }
            }
            if (i >= w.size()) {
                ans += w.size();
            }
        }
        return ans;
    }
};