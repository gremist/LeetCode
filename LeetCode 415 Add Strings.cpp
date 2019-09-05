// LeetCode 415 Add Strings.cpp

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, s1 = num1.size(), s2 = num2.size();
        string sum(max(s1, s2), 0);
        for (int i = 0, ss = sum.size(); i < ss; i++) {
            sum[ss - i - 1] += i < s1 ? num1[s1 - i - 1] - '0' : 0;
            sum[ss - i - 1] += i < s2 ? num2[s2 - i - 1] - '0' : 0;
            sum[ss - i - 1] += carry;
            carry = sum[ss - i - 1] / 10;
            sum[ss - i - 1] = sum[ss - i - 1] % 10 + '0';
        }
        if (carry > 0) {
            sum = to_string(carry) + sum;
        }
        return sum;
    }
};