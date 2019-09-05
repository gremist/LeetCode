// LeetCode 5 Longest Palindromic Substring.cpp

// Manacher's Algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string _s = "$#";
        for (char c : s) {
            _s += c;
            _s += "#";
        }
        
        vector<int> p(_s.size(), 0);
        int id = 0, max_id = 0;
        for (int i = 1; i < _s.size(); i++) {
            p[i] = p[id] + id > i ? min(p[2 * id - i], p[id] + id - i) : 1;
            while (_s[i + p[i]] == _s[i - p[i]]) {
                p[i]++;
            }
            if (p[i] + i > p[id] + id) {
                id = i;
                if (p[i] > p[max_id]) {
                    max_id = i;
                }
            }
        }
        return s.substr((max_id - p[max_id]) / 2, p[max_id] - 1);
    }
};