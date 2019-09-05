// LeetCode 166 Fraction to Recurring Decimal.cpp

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = numerator && numerator < 0 ^ denominator < 0 ? "-" : "";
        long num = labs(numerator), den = labs(denominator);
        
        ans += to_string(num / den);
        num %= den;
        if (!num) {
            return ans;
        }
        
        unordered_map<long, int> m;
        ans += ".";
        while (num) {
            if (m.find(num) != m.end()) {
                ans.insert(m[num], "(");
                return ans + ")";
            }
            m[num] = ans.size();
            ans += 10 * num / den + '0';
            num  = 10 * num % den;
        }
        return ans;
    }
};