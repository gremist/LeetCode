// LeetCode 929 Unique Email Addresses.cpp

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (string &email : emails) {
            string format;
            bool plus = false, at = false;
            for (char ch : email) {
                plus |= ch == '+';
                at   |= ch == '@';
                if (at || !plus && ch != '.') {
                    format += ch;
                }
            }
            s.insert(format);
        }
        return s.size();
    }
};