// LeetCode 389 Find the Difference.cpp

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for (char ch : s) {
            ans ^= ch;
        }
        for (char ch : t) {
            ans ^= ch;
        }
        return ans;
    }
};