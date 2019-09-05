// LeetCode 371 Sum of Two Integers.cpp

class Solution {
public:
    int getSum(int a, int b) {
        while (a & b) {
            int _xor = a ^ b;
            a = (a & b) << 1;
            b = _xor;
        }
        return a ^ b;
    }
};