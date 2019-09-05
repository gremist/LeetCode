// LeetCode 383 Ransom Note.cpp

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        vector<int> ht(26, 0);
        for (char ch : magazine) {
            ht[ch - 'a']++;
        }
        for (char ch : ransomNote) {
            if (--ht[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};