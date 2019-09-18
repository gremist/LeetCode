// LeetCode 788 Rotated Digits.cpp

// 方法1：逐位计算
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            int num = i;
            bool changed = false;
            while (num) {
                int rem = num % 10;
                if (rem == 3 || rem == 4 || rem == 7) {
                    break;
                }
                changed |= rem == 2 || rem == 5 ||
                    rem == 6 || rem == 9;
                num /= 10;
            }
            if (changed && !num) {
                count++;
            }
        }
        return count;
    }
};

// 方法2：动态规划
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; i++) {
            if (i == 3 || i == 4 || i == 7 ||
                dp[i % 10] == 1 || dp[i / 10] == 1) {
                dp[i] = 1;
            } else if (i == 2 || i == 5 || i == 6 || i == 9 ||
                dp[i % 10] == 2 || dp[i / 10] == 2) {
                dp[i] = 2;
                count++;
            }
        }
        return count;
    }
};

// 方法3：字符串
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            string num = to_string(i);
            if (num.find_first_of( "347") == -1 &&
                num.find_first_of("2569") != -1) {
                count++;
            }
        }
        return count;
    }
};