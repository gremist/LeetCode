// LeetCode 917 Reverse Only Letters.cpp

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size() - 1;
        while (i < j) {
            if (!isalpha(S[i])) {
                i++;
            } else if (!isalpha(S[j])) {
                j--;
            } else {
                swap(S[i++], S[j--]);
            }
        }
        return S;
    }
};