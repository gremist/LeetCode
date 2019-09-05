// LeetCode 258 Add Digits.cpp

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};