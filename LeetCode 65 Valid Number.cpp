// LeetCode 65 Valid Number.cpp

class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        for (int i = 0; state != -1 && i < s.size(); i++) {
            switch (s[i]) {
            case ' ':
                state = trans[state][0];
                break;
            case '+':
            case '-':
                state = trans[state][1];
                break;
            case '.':
                state = trans[state][2];
                break;
            case 'e':
                state = trans[state][3];
                break;
            default:
                state = isdigit(s[i]) ? trans[state][4] : -1;
            }
        }
        return state >= 5;
    }
    
private:
    vector<vector<int>> trans = {
        { 0,  1,  2, -1,  5}, {-1, -1,  2, -1,  5}, {-1, -1, -1, -1,  6},
        {-1,  4, -1, -1,  7}, {-1, -1, -1, -1,  7}, { 8, -1,  6,  3,  5},
        { 8, -1, -1,  3,  6}, { 8, -1, -1, -1,  7}, { 8, -1, -1, -1, -1}
    };
};