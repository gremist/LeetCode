// LeetCode 693 Binary Number with Alternating Bits.cpp

class Solution {
public:
    bool hasAlternatingBits(int n) {
        return (n + (n >> 1) & n + (n >> 1) + 1) == 0;
    }
};