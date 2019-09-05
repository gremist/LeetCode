// LeetCode 1047 Remove All Adjacent Duplicates In String.cpp

class Solution {
public:
    string removeDuplicates(string S) {
        int top = 0;
        for (char ch : S) {
            if (top == 0 || S[top - 1] != ch) {
                S[top++] = ch;
            } else {
                top--;
            }
        }
        S.resize(top);
        return S;
    }
};