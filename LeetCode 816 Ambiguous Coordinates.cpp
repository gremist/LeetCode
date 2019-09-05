// LeetCode 816 Ambiguous Coordinates.cpp

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        for (int i = 1; i < S.size() - 2; i++) {
            vector<string> X, Y;
            insertPoint(X, S.substr(1, i));
            insertPoint(Y, S.substr(i + 1, S.size() - i - 2));
            for (string &x : X) {
                for (string &y : Y) {
                    ans.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }
    
private:
    void insertPoint(vector<string> &ans, string S) {
        if (S.front() != '0' || S.size() == 1) {
            ans.push_back(S);
        }
        if (S.back()  != '0' && S.size()  > 1) {
            ans.push_back(S.substr(0, 1) + "." + S.substr(1));
        }
        if (S.front() != '0' && S.back() != '0') {
            for (int i = 2; i < S.size(); i++) {
                ans.push_back(S.substr(0, i) + "." + S.substr(i));
            }
        }
    }
};