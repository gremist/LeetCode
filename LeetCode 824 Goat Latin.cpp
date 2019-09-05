// LeetCode 824 Goat Latin.cpp

class Solution {
public:
    string toGoatLatin(string S) {
        istringstream iss(S);
        string ans, buf, a;
        while (iss >> buf) {
            if (vowels.find(buf[0]) != vowels.end()) {
                ans += buf;
            } else {
                ans += buf.substr(1);
                ans += buf[0];
            }
            ans += "ma";
            ans += a += "a";
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
    
private:
    unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
};