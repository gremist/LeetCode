// LeetCode 409 Longest Palindrome.cpp

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> ht(128);
        for (char ch : s) {
            ht[ch]++;
        }
        int ans = 0;
        for (int i : ht) {
            ans += i / 2 * 2;
        }
        return ans == s.size() ? ans : ans + 1;
    }
};