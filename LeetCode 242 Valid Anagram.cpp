// LeetCode 242 Valid Anagram.cpp

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> ht(26);
        for (int i = 0; i < s.size(); i++) {
            ht[s[i] - 'a']++;
            ht[t[i] - 'a']--;
        }
        for (int x : ht) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};