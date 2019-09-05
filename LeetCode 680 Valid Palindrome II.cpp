// LeetCode 680 Valid Palindrome II.cpp

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                break;
            }
            i++;
            j--;
        }
        while (i < j) {
            if (s[i + 1] != s[j] && s[i] != s[j - 1]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};