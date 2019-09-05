// LeetCode 1108 Defanging an IP Address.cpp

class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for (char ch : address) {
            if (ch == '.') {
                ans += "[.]";
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};