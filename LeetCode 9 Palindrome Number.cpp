// LeetCode 9 Palindrome Number.cpp

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int _x = x, y = 0;
        while (_x) {
            y *= 10;
            y += _x % 10;
            _x /= 10;
        }
        return x == y;
    }
};