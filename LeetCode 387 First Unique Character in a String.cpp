// LeetCode 387 First Unique Character in a String.cpp

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ht(26);
        for (int i = 0; i < s.size(); i++) {
            ht[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (ht[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};