// LeetCode 6 ZigZag Conversion.cpp

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> vec(numRows);
        for (int i = 0, x = numRows - 1; i < s.size(); i++) {
            vec[x - abs(i % (2 * x) - x)] += s[i];
        }
        
        string ans;
        for (string &str : vec) {
            ans += str;
        }
        return ans;
    }
};