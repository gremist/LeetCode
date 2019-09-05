// LeetCode 231 Power of Two.cpp

// 方法1：迭代
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};

// 方法2：位运算
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// 方法3：整数限制
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && 1073741824 % n == 0;
    }
};