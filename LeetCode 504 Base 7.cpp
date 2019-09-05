// LeetCode 504 Base 7.cpp

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        if (num  < 0) return "-" + convertToBase7(-num);
        
        string ans;
        while (num) {
            ans += num % 7 + '0';
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};