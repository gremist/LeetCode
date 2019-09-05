// LeetCode 500 Keyboard Row.cpp

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (string &w : words) {
            uint8_t byte = 7;
            for (char ch : w) {
                byte &= ht[tolower(ch) - 'a'];
                if (!byte) {
                    break;
                }
            }
            if (byte) {
                ans.push_back(w);
            }
        }
        return ans;
    }

private:
    vector<uint8_t> ht = {2, 4, 4, 2, 1, 2, 2, 2, 1, 2,
        2, 2, 4, 4, 1, 1, 1, 1, 2, 1, 1, 4, 1, 4, 1, 4};
};