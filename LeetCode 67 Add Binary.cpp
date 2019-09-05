// LeetCode 67 Add Binary.cpp

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, as = a.size(), bs = b.size();
        string sum(max(as, bs), 0);
        for (int i = 0, ss = sum.size(); i < ss; i++) {
            sum[ss - i - 1] += i < as ? a[as - i - 1] - '0' : 0;
            sum[ss - i - 1] += i < bs ? b[bs - i - 1] - '0' : 0;
            sum[ss - i - 1] += carry;
            carry = sum[ss - i - 1] / 2;
            sum[ss - i - 1] = sum[ss - i - 1] % 2 + '0';
        }
        if (carry > 0) {
            sum = to_string(carry) + sum;
        }
        return sum;
    }
};