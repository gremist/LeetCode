// LeetCode 125 Valid Palindrome.cpp

class Solution {
public:
    bool isPalindrome(string s) {
        string valid_s;
        for (char c : s) {
            if (isalnum(c)) {
                valid_s += tolower(c);
            }
        }
        
        int i = 0, j = valid_s.size() - 1;
        while (i < j) {
            if (valid_s[i++] != valid_s[j--]) {
                return false;
            }
        }
        return true;
    }
};