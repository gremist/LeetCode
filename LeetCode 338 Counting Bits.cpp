// LeetCode 338 Counting Bits.cpp

// 方法1：迭代
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++) {
            ans[i] = ans[i / 2] + i % 2;
        }
        return ans;
    }
};

// 方法2：迭代
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};