// LeetCode 476 Number Complement.cpp

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while (num & mask) {
            mask <<= 1;
        }
        return ~mask ^ num;
    }
};