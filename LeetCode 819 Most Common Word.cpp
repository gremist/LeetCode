// LeetCode 819 Most Common Word.cpp

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> m;
        for (string &str : banned) {
            m[str] = -1;
        }
        
        string buf, ans;
        paragraph += " ";
        for (char ch : paragraph) {
            if (isalpha(ch)) {
                buf += tolower(ch);
            } else if (!buf.empty()) {
                if (m[buf] != -1 && ++m[buf] > m[ans]) {
                    ans = buf;
                }
                buf.clear();
            }
        }
        return ans;
    }
};