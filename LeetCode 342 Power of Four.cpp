// LeetCode 342 Power of Four.cpp

// 方法1：迭代
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) return false;
        while (num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};

// 方法2：位运算
class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && num % 3 == 1;
    }
};